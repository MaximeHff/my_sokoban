/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** tools
*/

#include "include/sokoban.h"
#include "include/myprintf.h"

int my_strlen(char const *str)
{
    int i = 0;

    for (; str[i] != '\0'; i++);
    return (i);
}

int my_tabline(char **str)
{
    int i = 0;
    int p = 0;
    int count = 0;

    for (int z = 0; str[z] != NULL; z++) {
        i++;
        for (; str[z][p] != '\0'; p++) {
            i++;
            if (str[z][p] == '\n')
                count += 1;
        }
        p = 0;
    }
    return (count);
}

int my_tabcol(char **str)
{
    int i = 0;
    int p = 0;
    int count = 0;

    for (int z = 0; z != 1; z++) {
        i++;
        for (; str[z][p] != '\0'; p++) {
            count += 1;
            i++;
        }
        p = 0;
    }
    return (count);
}

int my_tablen(char **str)
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

int check_space(char *str)
{
    int space = 2;

    for (int z = 0; str[z] != '\0'; z++)
        if (str[z] == '\n')
            space++;
    return (space);
}