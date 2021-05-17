/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** restart
*/

#include "include/sokoban.h"
#include "include/myprintf.h"

void restart_game(soko_t *data)
{
    refresh();
    center_map(data, data->av_backup);
    clear();
}

int my_strtab(char **str)
{
    int i = 0;
    int p = 0;

    for (int z = 0; str[z] != NULL; z++) {
        i++;
        for (; str[z][p] != '\0'; p++)
            i++;
        p = 0;
    }
    return (i);
}

char **malloc_double_tab(char **str, int space)
{
    char **my_tab;
    int p = 0;

    my_tab = malloc(sizeof(char *) * (space + 2));
    for (; p < space; p++)
        my_tab[p] = malloc(sizeof(char) * (my_strtab(str) + 4));
    my_tab[p] = NULL;
    return (my_tab);
}

int check_space_tab(char **str)
{
    int space = 1;
    int w = 0;

    for (int z = 0; str[z] != NULL; z++) {
        for (; str[z][w] != '\0'; w++);
        w = 0;
        space++;
    }
    return (space);
}

char **my_str_to_word_array_tab(char **str, soko_t *data)
{
    data->av_backup = malloc(sizeof(char *) * 7);
    int space = check_space_tab(str);
    int x = 0;
    int y = 0;

    data->av_backup = malloc_double_tab(str, space);
    for (int i = 0; str[i] != NULL; x++) {
        for (int p = 0; str[i][p] != '\0'; p++) {
            data->av_backup[x][y] = str[i][p];
            y++;
        }
        data->av_backup[x][y] = '\0';
        i++;
        y = 0;
    }
    data->av_backup[x] = NULL;
    return (data->av_backup);
}