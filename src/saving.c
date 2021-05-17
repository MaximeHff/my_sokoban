/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** saving
*/

#include "include/sokoban.h"
#include "include/myprintf.h"

void my_o(soko_t *data)
{
    int i = 0;
    int z = 0;

    data->savo1 = malloc(sizeof(int) * (data->o + 2));
    data->savo2 = malloc(sizeof(int) * (data->o + 2));
    for (; data->map[i] != NULL; i++) {
        for (int y = 0; data->map[i][y] != '\0'; y++)
            if (data->map[i][y] == 'O') {
                data->savo1[z] = i;
                data->savo2[z] = y;
                z++;
            }
    }
    data->savo1[z] = -1;
    data->savo2[z] = -1;
}

void replace_o(soko_t *data)
{
    for (int i = 0; data->savo1[i] != -1; i++)
        if (data->map[data->savo1[i]][data->savo2[i]] == ' ')
            data->map[data->savo1[i]][data->savo2[i]] = 'O';
}

int check_o(soko_t *data)
{
    int i = 0;

    for (; data->savo1[i] != -1; i++)
        if (data->map[data->savo1[i]][data->savo2[i]] != 'X')
            return (0);
    if (data->savo1[i] == -1) {
        data->game_on = 1;
        return (-1);
    }
    return (0);
}

void my_x(soko_t *data, int row, int col)
{
    int i = 0;
    int z = 0;

    data->savex1 = malloc(sizeof(int) * (data->o + 2));
    data->savex2 = malloc(sizeof(int) * (data->o + 2));
    for (; data->map[i] != NULL; i++) {
        for (int y = 0; data->map[i][y] != '\0'; y++)
            if (data->map[i][y] == 'X') {
                data->savex1[z] = i;
                data->savex2[z] = y;
                z++;
            }
    }
    data->savex1[z] = -1;
    data->savex2[z] = -1;
    check_x(data, row, col);
}