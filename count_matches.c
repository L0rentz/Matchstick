/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** count_matches
*/

#include "my.h"

int count_matches_on_line(int line, char **map)
{
    int count = 0;
    for (int i = 1; map[line][i] != '*' ; i++)
        if (map[line][i] == '|')
            count++;
    return (count);
}

int count_alone_matches(char **map)
{
    int alone = 0;
    int line_count = 0;
    for (int i = 1; map[i] != NULL; i++) {
        for (int j = 1; map[i][j] != '*'; j++) {
            if (map[i][j] == '|')
                line_count++;
        } if (line_count == 1)
            alone += 1;
        line_count = 0;
    }
    return (alone);
}

int matches_number(char **map, int lines)
{
    int nb = 0;
    int cols = lines * 2;
    for (int i = 1; i != lines + 1; i++) {
        for (int j = 1; j != cols; j++)
            if (map[i][j] == '|')
                nb++;
    }
    return (nb);
}