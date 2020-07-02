/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** create_map
*/

#include "my.h"

char **copy_map(char **map, int lines)
{
    char **map_cpy = malloc(sizeof(char *) * (lines + 3));
    int cols = lines * 2 + 1;
    for (int i = 0; i != lines + 2; i++)
        map_cpy[i] = malloc(sizeof(char) * (cols + 1));
    int i = 0;
    for (int j = 0; map[i] != NULL; i++) {
        for (j = 0; map[i][j] != '\0' && j != lines * 2 + 1; j++)
            map_cpy[i][j] = map[i][j];
        map_cpy[i][j] = '\0';
    }
    map_cpy[i] = NULL;
    return (map_cpy);
}

char **create_map(int lines)
{
    int cols = lines * 2 + 1, matchs = lines * 2 - 1, offset = 1;
    char **map = malloc(sizeof(char *) * (lines + 3));
    for (int i = 0; i != lines + 2; i++)
        map[i] = malloc(sizeof(char) * (cols + 1));
    map[lines + 2] = NULL;
    for (int i = 0; i != lines + 2; i++) {
        for (int j = 0; j != cols - 1; j++)
            map[i][j] = ' ';
        map[i][0] = '*';
        map[i][cols - 1] = '*';
        map[i][cols] = '\0';
    }
    for (int i = 0; i != cols; i++)
        map[0][i] = '*', map[lines + 1][i] = '*';
    for (int i = lines; i != 0; i--) {
        for (int j = offset, k = 0; k < matchs; j++, k++)
            map[i][j] = '|';
        matchs -= 2, offset += 1;
    }
    return (map);
}