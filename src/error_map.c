/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** error_map
*/

#include "include/sokoban.h"
#include "include/myprintf.h"

int check_up_line(soko_t *data, int i)
{
    int z = 0;

    if (data->map[data->savex1[i] - 1][data->savex2[i]] == '#')
        for (; data->savo2[z] != -1; z++) {
            if ((data->map[data->savex1[i]][data->savo2[z]] == 'O' ||
            data->backup[data->savex1[i]][data->savex2[i]] == 'O') &&
            data->savex1[i] == 1)
                return (0);
            if (data->savex1[i] != 1 &&
            (data->map[data->savex1[i]][data->savo2[z]] != 'O' ||
            data->backup[data->savex1[i]][data->savex2[i]] != 'O'))
                return (0);
        }
        if (data->savo2[z] == -1)
            data->game_on = 2;
    return (0);
}

int check_down_line(soko_t *data, int i)
{
    int z = 0;
    int last_line = my_tabline(data->map) - 2;

    if (data->map[data->savex1[i] + 1][data->savex2[i]] == '#')
        for (; data->savo2[z] != -1; z++) {
            if ((data->map[data->savex1[i]][data->savo2[z]] == 'O' ||
            data->backup[data->savex1[i]][data->savex2[i]] == 'O') &&
            data->savex1[i] == last_line)
                return (0);
            if ((data->savex1[i] != last_line) &&
            (data->map[data->savex1[i]][data->savo2[z]] != 'O' ||
            data->backup[data->savex1[i]][data->savex2[i]] != 'O'))
                return (0);
        }
        if (data->savo2[z] == -1)
            data->game_on = 2;
    return (0);
}

int check_right_line(soko_t *data, int i)
{
    int z = 0;
    int last_line = my_tabcol(data->map) - 3;

    for (; data->savo2[z] != -1; z++)
        for (int k = 0; k != (my_tabline(data->map)); k++) {
            if ((data->map[k][last_line] == 'O' ||
            data->backup[data->savex1[i]][data->savex2[i]] == 'O') &&
            data->savex2[i] == last_line)
                return (0);
            if ((data->savex2[i] != last_line) &&
            (data->map[k][last_line] != 'O' ||
            data->backup[data->savex1[i]][data->savex2[i]] != 'O'))
                return (0);
        }
    if (data->savo1[z] == -1)
        data->game_on = 2;
    return (0);
}

int check_left_line(soko_t *data, int i)
{
    int z = 0;
    int last_line = 1;

    for (; data->savo2[z] != -1; z++)
        for (int k = 0; k != (my_tabline(data->map)); k++) {
            if ((data->map[k][last_line] == 'O' ||
            data->backup[data->savex1[i]][data->savex2[i]] == 'O') &&
            data->savex2[i] == last_line)
                return (0);
            if ((data->savex2[i] != last_line) &&
            (data->map[k][last_line] != 'O' ||
            data->backup[data->savex1[i]][data->savex2[i]] != 'O'))
                return (0);
        }
    if (data->savo1[z] == -1)
        data->game_on = 2;
    return (0);
}

int check_x(soko_t *data, int row, int col)
{
    int i = 0;
    int count = 0;

    for (; data->savex1[i] != -1; i++) {
        if ((data->map[data->savex1[i] - 1][data->savex2[i]] == '#') && 
        (data->map[data->savex1[i]][data->savex2[i] - 1] == '#') || 
        (data->map[data->savex1[i] + 1][data->savex2[i]] == '#') && 
        (data->map[data->savex1[i]][data->savex2[i] - 1] == '#') ||
        (data->map[data->savex1[i] + 1][data->savex2[i]] == '#') && 
        (data->map[data->savex1[i]][data->savex2[i] + 1] == '#') ||
        (data->map[data->savex1[i] - 1][data->savex2[i]] == '#') && 
        (data->map[data->savex1[i]][data->savex2[i] + 1] == '#'))
            data->game_on = 2;
        if (count == (data->xx * 2))
            data->game_on = 2;
        check_xx(data);
        check_up_line(data, i);
        check_down_line(data, i);
        repartition_left_right(data, i);
    }
    return (0);
}