/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** win
*/

#include "include/sokoban.h"
#include "include/myprintf.h"

int win(soko_t *data, int row, int col)
{
    mvprintw((LINES/2) - 1, (COLS/2) - 5, "You win !");
    mvprintw((LINES/2), (COLS/2) - 8, "Press m to quit");
    mvprintw((LINES/2) + 1, (COLS/2) - 11.5, "Press SPACE to restart");
    if (data->key == 'm')
        return (-1);
}

int loose(soko_t *data, int row, int col)
{
    mvprintw((LINES/2) - 1, (COLS/2) - 6, "You lose !");
    mvprintw((LINES/2), (COLS/2) - 8, "Press m to quit");
    mvprintw((LINES/2) + 1, (COLS/2) - 11.5, "Press SPACE to restart");
    if (data->key == 'm')
        return (-1);
}

int loose_with_time(soko_t *data, int row, int col)
{
    clear();
    mvprintw((LINES/2) - 1, (COLS/2) - 6, "You lose !");
    mvprintw((LINES/2), (COLS/2) - 8, "Press m to quit");
    mvprintw((LINES/2) + 1, (COLS/2) - 11.5, "Press SPACE to restart");
    if (data->key == 'm')
        return (-1);
    refresh();
    usleep(5000000);
    return (-1);
}

int win_with_time(soko_t *data, int row, int col)
{
    clear();
    mvprintw((LINES/2) - 1, (COLS/2) - 5, "You win !");
    mvprintw((LINES/2), (COLS/2) - 8, "Press m to quit");
    mvprintw((LINES/2) + 1, (COLS/2) - 11.5, "Press SPACE to restart");
    if (data->key == 'm')
        return (-1);
    refresh();
    usleep(5000000);
    return (-1);
}

int check_xx(soko_t *data)
{
    int i = 0;

    for (; data->savex1[i] != -1; i++) {
        if (((data->map[data->savex1[i]][data->savex2[i] + 1] == 'X') &&
        (data->map[data->savex1[i] - 1][data->savex2[i]] == '#') &&
        (data->map[data->savex1[i] + 1][data->savex2[i]] == '#') ||
        (data->map[data->savex1[i]][data->savex2[i] - 1] == 'X') &&
        (data->map[data->savex1[i] - 1][data->savex2[i]] == '#') &&
        (data->map[data->savex1[i] + 1][data->savex2[i]] == '#') ||
        (data->map[data->savex1[i] + 1][data->savex2[i]] == 'X') &&
        (data->map[data->savex1[i]][data->savex2[i] + 1] == '#') &&
        (data->map[data->savex1[i]][data->savex2[i] - 1] == '#') ||
        (data->map[data->savex1[i] - 1][data->savex2[i]] == 'X') &&
        (data->map[data->savex1[i]][data->savex2[i] - 1] == '#') &&
        (data->map[data->savex1[i]][data->savex2[i] + 1] == '#')) &&
        (data->backup[data->savex1[i]][data->savex2[i]] != 'O'))
            data->game_on = 2;
    }
    return (0);
}