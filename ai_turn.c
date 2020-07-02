/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** ai_turn
*/

#include "my.h"

int xor_all_lines(char **map)
{
    int xor = count_matches_on_line(1, map);
    int count = 0;
    for (int i = 2; map[i] != NULL; i++) {
        count = count_matches_on_line(i, map);
        xor ^= count;
    }
    return (xor);
}

int ai_find_largest_line(char **map, int lines)
{
    int largest = 0, comp = 0, line = 0;
    for (int i = 1; i != lines + 1; i++) {
        for (int j = 1; map[i][j] != '*'; j++)
            if (map[i][j] == '|')
                comp++;
        if (comp > largest) {
            largest = comp;
            line = i;
        }
        comp = 0;
    }
    return (line);
}

int find_pos_last_match(char **map, int lines, int line)
{
    int cols = 2 * lines + 1;
    for (; map[line][cols] != '|'; cols--);
    return (cols);
}

char **ai_turn(char **map, int nb, int lines)
{
    int line = ai_find_largest_line(map, lines);
    int count = count_matches_on_line(line, map);
    if (count > nb) count = nb;
    int matches = xor_all_lines(map);
    int last = find_pos_last_match(map, lines, line);
    if (matches > count || matches == 0) {
        matches = rand() % count;
        if (matches == 0)
            matches = 1;
    } if (((count_alone_matches(map) % 2 == 0 && count_alone_matches(map) != 0
    && matches == count_matches_on_line(line, map))
    || matches_number(map, lines) == matches) && matches != 1) matches--;
    int how_many = matches;
    while (matches != 0)
        map[line][last] = ' ', last--, matches--;
    if (count_alone_matches(map) % 2 == 0
    && count_matches_on_line(line, map) == 1)
        map[line][last] = ' ', how_many++;
    my_printf("\nAI's turn...\n");
    my_printf("AI removed %d match(es) from line %d\n", how_many, line);
    return (map);
}
