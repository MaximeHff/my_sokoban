/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** sokoban
*/

#include "include/sokoban.h"
#include "include/myprintf.h"

void my_init(soko_t *data, char **av)
{
    data->player = 0;
    data->game_on = 0;
    my_str_to_word_array(open_map(av), data);
    check_map(data);
    check_nb_elements(data);
    my_o(data);
}

int my_loop(soko_t *data, int row, int col)
{
    replace_o(data);
    refresh();
    check_o(data);
}

int center_map(soko_t *data, char **av)
{
    int row = 0;
    int col = 0;

    my_init(data, av);
    initscr();
    keypad(stdscr, TRUE);
    curs_set(0);
    while (1) {
        search_p(data, row, col);
        getmaxyx(stdscr, row, col);
        if (event(row, col, data) == -1)
            return (0);
        if (event(row, col, data) == -2)
            return (1);
        data->key = getch();
        if (repartition_key(data) == -1)
            break;
        my_loop(data, row, col);
    }
    endwin();
    return (0);
}

int main(int ac, char **av)
{
    soko_t *data = malloc(sizeof(soko_t));

    my_str_to_word_array_tab(av, data);
    path_error(ac, av);
    if (center_map(data, av) == 1) {
        endwin();
        return (1);
    }
    endwin();
    return (0);
}