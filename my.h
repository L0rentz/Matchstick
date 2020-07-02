/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** header
*/

#ifndef CPE_MATCHSTICK_2019_MY_H
#define CPE_MATCHSTICK_2019_MY_H

#include "my_printf/my_printf.h"
#include "get_next_line/get_next_line.h"
#include <stdlib.h>
#include <stdio.h>

int my_atoi(char const *str);
char **create_map(int lines);
char **player_turn(char **map, int cols, int *lines, int nb);
int count_matches_on_line(int line, char **map);
int matches_number(char **map, int lines);
char **copy_map(char **map, int lines);
char **ai_turn(char **map, int nb, int lines);
int count_alone_matches(char **map);

#endif
