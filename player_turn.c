/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** player_turn
*/

#include "my.h"

int get_matches(int *err, int nb, int line, char **map)
{
    int matches = 0;
    my_printf("Matches: ");
    char *str = get_next_line(0);
    if (str == NULL) {
        *err = -1;
        return (-1); }
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9') {
            my_printf("Error: invalid input (positive number expected)\n");
            return (0);
        } matches = my_atoi(str), free(str);
    if (matches > nb)
        my_printf("Error: you cannot remove more than %d matches per "
                    "turn\n", nb);
    if (matches <= nb && matches > count_matches_on_line(line, map)) {
        my_printf("Error: not enough matches on this line\n");
        return (0);
    } if (matches == 0)
        my_printf("Error: you have to remove at least one match\n");
    return (matches);
}

int get_line(int *error)
{
    int line = 0;
    if (*error > 0)
        my_printf("Error: this line is out of range\n");
    my_printf("Line: ");
    char *str = get_next_line(0);
    if (str == NULL) return (-1);
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] < '0' || str[i] > '9') {
            my_printf("Error: invalid input (positive number expected)\n");
            *error = -1;
            return (0);
        }
    line = my_atoi(str);
    free(str);
    return (line);
}

char **player_turn(char **map, int cols, int *lines, int nb)
{
    int line = 0, matches = 0;
    my_printf("\nYour turn:\n");
    for (int err = 0; (line < 1 || line > *lines)
    || (matches < 1 || matches > nb);) {
        line = 0, matches = 0;
        for (int error = 0; line < 1 || line > *lines; error++) {
            line = get_line(&error);
            if (line == -1 && error != -1) {
                *lines = -1;
                return (map);
            }
        } matches = get_matches(&err, nb, line, map);
        if (matches == -1 && err == -1) {
            *lines = -1;
            return (map);
        }
    } my_printf("Player removed %d match(es) from line %d\n", matches, line);
    for (; map[line][cols] != '|'; cols--);
    for (; matches != 0; matches--, cols--) map[line][cols] = ' ';
    return (map);
}
