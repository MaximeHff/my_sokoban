/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** event
*/

#include "include/sokoban.h"
#include "include/myprintf.h"

void check_nb_elements(soko_t *data)
{
    if (data->xx != data->o) {
        write(2, "error map: you don't have the same ", 36);
        write(2, "number of 'X' and 'O'.\n", 24);
        exit(84);
    }
}

int event(int row, int col, soko_t *data)
{
    clear();
    if (data->game_on == 1)
        if (win(data, row, col) == -1)
            return (-1);
    if (data->game_on == 2)
        if (loose(data, row, col) == -1)
            return (-2);
    if (data->game_on == 0)
        terminal_size(data, row, col);
    if (data->key == 'm')
        return (-1);
    return (0);
}

void search_p(soko_t *data, int row, int col)
{
    int i = 0;

    my_x(data, row, col);
    for (; data->map[i] != NULL; i++) {
        for (int y = 0; data->map[i][y] != '\0'; y++)
            if (data->map[i][y] == 'P') {
                data->x = i;
                data->y = y;
            }
    }
}