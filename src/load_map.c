/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** load_map
*/

#include "include/sokoban.h"
#include "include/myprintf.h"

void my_map(soko_t *data)
{
    int size_tab = my_strlen(data->map[0]);

    for (int i = 0; data->map[i]; i++)
        mvprintw((LINES/2)+i-(my_tabline(data->map)/2),
        (COLS/2)-(size_tab/2), data->map[i]);
}

char **malloc_double(char *str, int space)
{
    char **my_tab;
    int p = 0;

    my_tab = malloc(sizeof(char *) * (space + 2));
    for (; p < space; p++)
        my_tab[p] = malloc(sizeof(char) * (my_strlen(str) + 2));
    my_tab[p] = NULL;
    return (my_tab);
}

void my_str_to_word_array(char *str, soko_t *data)
{
    int space = check_space(str);
    int x = 0;
    int y = 0;

    data->map = malloc_double(str, space);
    data->backup = malloc_double(str, space);
    for (int i = 0; i <= my_strlen(str); x++) {
        for (; str[i] != '\n' && str[i]; i++) {
            data->map[x][y] = str[i];
            data->backup[x][y] = str[i];
            y++;
        }
        data->map[x][y] = '\n';
        data->backup[x][y] = '\n';
        i++;
        y = 0;
    }
    data->map[x][y] = '\0';
    data->backup[x][y] = '\0';
}

char *open_map(char **av)
{
    struct stat buffer;
    int fd = open(av[1], O_RDONLY);
    int size = 0;
    char *map;

    stat(av[1], &buffer);
    size = buffer.st_size;
    map = malloc(sizeof(char) * size + 1);
    read(fd, map, size);
    map[size] = '\0';
    if (map[0] == '\0') {
        write(2, "path error: your path is inexistent.\n", 38);
        exit(84);
    }
    return (map);
}