/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** keybord
*/

#include "include/sokoban.h"
#include "include/myprintf.h"

void key_up(soko_t *data)
{
    if (data->map[data->x - 1][data->y] != '#' &&
    data->map[data->x - 1][data->y] != 'X') {
        data->map[data->x - 1][data->y] = 'P';
        data->map[data->x][data->y] = ' ';
    }
    if (data->map[data->x - 1][data->y] == 'X' &&
    (data->map[data->x - 2][data->y] != '#') &&
    data->map[data->x - 2][data->y] != 'X') {
        data->map[data->x - 1][data->y] = 'P';
        data->map[data->x][data->y] = ' ';
        data->map[data->x - 2][data->y] = 'X';
    }
}

void key_down(soko_t *data)
{
    if (data->map[data->x + 1][data->y] != '#' &&
    data->map[data->x + 1][data->y] != 'X') {
        data->map[data->x + 1][data->y] = 'P';
        data->map[data->x][data->y] = ' ';
    }
    if (data->map[data->x + 1][data->y] == 'X' &&
    (data->map[data->x + 2][data->y] != '#') &&
    data->map[data->x + 2][data->y] != 'X') {
        data->map[data->x + 1][data->y] = 'P';
        data->map[data->x][data->y] = ' ';
        data->map[data->x + 2][data->y] = 'X';
    }
}

void key_left(soko_t *data)
{
    if (data->map[data->x][data->y - 1] != '#' &&
    data->map[data->x][data->y - 1] != 'X') {
        data->map[data->x][data->y - 1] = 'P';
        data->map[data->x][data->y] = ' ';
    }
    if (data->map[data->x][data->y - 1] == 'X' &&
    (data->map[data->x][data->y - 2] != '#') &&
    data->map[data->x][data->y - 2] != 'X') {
        data->map[data->x][data->y - 1] = 'P';
        data->map[data->x][data->y] = ' ';
        data->map[data->x][data->y - 2] = 'X';
    }
}

void key_right(soko_t *data)
{
    if (data->map[data->x][data->y + 1] != '#' &&
    data->map[data->x][data->y + 1] != 'X') {
        data->map[data->x][data->y + 1] = 'P';
        data->map[data->x][data->y] = ' ';
    }
    if (data->map[data->x][data->y + 1] == 'X' &&
    (data->map[data->x][data->y + 2] != '#') &&
    data->map[data->x][data->y + 2] != 'X') {
        data->map[data->x][data->y + 1] = 'P';
        data->map[data->x][data->y] = ' ';
        data->map[data->x][data->y + 2] = 'X';
    }
}

int repartition_key(soko_t *data)
{
    switch (data->key) {
        case KEY_UP:
            key_up(data);
            break;
        case KEY_DOWN:
            key_down(data);
            break;
        case KEY_LEFT:
            key_left(data);
            break;
        case KEY_RIGHT:
            key_right(data);
            break;
        case ' ':
            restart_game(data);
            break;
    }
    return (0);
}