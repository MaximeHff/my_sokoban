/*
** EPITECH PROJECT, 2021
** B-PSU-200-STG-2-1-mysokoban-maxime.hoffbeck
** File description:
** sokoban
*/

#include <curses.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

#ifndef SOKOBAN_H_
#define SOKOBAN_H_

typedef struct soko_s {
    int player;
    char **map;
    char **backup;
    int x;
    int y;
    int o;
    int xx;
    int *savo1;
    int *savo2;
    int *savex1;
    int *savex2;
    char **av_backup;
    int game_on;
    int key;
} soko_t;

char *open_map(char **av);
void my_str_to_word_array(char *str, soko_t *data);
char **malloc_double(char *str, int space);
int center_map(soko_t *data, char **av);
int my_strlen(char const *str);
int my_tablen(char **str);
int check_elements(int i, int j, soko_t *data);
int check_map(soko_t *data);
int my_tabline(char **str);
int path_error(int ac, char **av);
int my_tabcol(char **str);
void terminal_size(soko_t *data, int row, int col);
void my_map(soko_t *data);
int check_space(char *str);
void arrow(int key);
int event(int row, int col, soko_t *data);
void search_p(soko_t *data, int row, int col);
int repartition_key(soko_t *data);
void check_nb_elements(soko_t *data);
void my_o(soko_t *data);
void replace_o(soko_t *data);
int check_o(soko_t *data);
void restart_game(soko_t *data);
char **my_str_to_word_array_tab(char **str, soko_t *data);
int win(soko_t *data, int row, int col);
int loose(soko_t *data, int row, int col);
void my_x(soko_t *data, int row, int col);
int check_x(soko_t *data, int row, int col);
int check_right_line(soko_t *data, int i);
int check_left_line(soko_t *data, int i);
int repartition_left_right(soko_t *data, int i);
int check_xx(soko_t *data);

#endif /* !SOKOBAN_H_ */