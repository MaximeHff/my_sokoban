/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** error
*/

#include "include/sokoban.h"
#include "include/myprintf.h"

int repartition_left_right(soko_t *data, int i)
{
    int z = 0;

    if (data->map[data->savex1[i]][data->savex2[i] + 1] == '#')
            check_right_line(data, i);
    if (data->map[data->savex1[i]][data->savex2[i] - 1] == '#')
            check_left_line(data, i);
    return (0);
}

void terminal_size(soko_t *data, int row, int col)
{
    if (row < (my_tabline(data->map)/2) + (LINES/2) + 1)
        mvprintw((LINES/2), (COLS/2) - 14, "Enlarge the terminal please");
    else if (col < (my_tabcol(data->map)/2) + (COLS/2) + 1)
        mvprintw((LINES/2), (COLS/2) - 14, "Enlarge the terminal please");
    else
        my_map(data);
}

int check_elements(int i, int j, soko_t *data)
{
    if (data->map[i][j] == 'P')
        data->player += 1;
    if (data->player > 1) {
        write(2, "error map: you have too many player 'P'.\n", 42);
        exit(84);
    }
    if (data->map[i][j] == 'O')
        data->o++;
    if (data->map[i][j] == 'X')
        data->xx++;
    return (0);
}

int check_map(soko_t *data)
{
    int j = 0;

    for (int i = 0; data->map[i] != NULL; i++) {
        for (; data->map[i][j] != '\n' && data->map[i][j]; j++) {
            if (data->map[i][j] != ' ' && data->map[i][j] != '\n'
            && data->map[i][j] != '#' && data->map[i][j] != 'X' &&
            data->map[i][j] != 'O' && data->map[i][j] != 'P'
            && data->map[i][j] != '\0') {
                write(2, "error map: only the characters SPACE,", 34);
                write(2, " '\\n', '#', 'X', 'O' and 'P' are valid.\n", 41);
                exit(84);
            }
            check_elements(i, j, data);
        }
        j = 0;
    }
    if (data->player == 0) {
        write(2, "map error: you don't have player 'P'.\n", 39);
        exit(84);
    }
    return (0);
}

int path_error(int ac, char **av)
{
    if (ac != 2) {
        write(2, "./my_sokoban -h for more details.\n", 35);
        exit(84);
    }
    if (av[1][0] == '-' && av[1][1] == 'h') {
        my_printf("USAGE\n\t./my_sokoban map.txt\n");
        my_printf("DESCRIPTION\n\tmap\tfile representing the warehouse map");
        my_printf(", containing '#' for walls, 'P' for the player, 'X' for");
        my_printf(" boxes and 'O' for storage locations.\n");
        my_printf("\tSPACE\treset the game.\n\tm\tquit the game.\n");
        exit(0);
    }
    return (0);
}