/*
** EPITECH PROJECT, 2020
** CPE_matchstick_2019
** File description:
** main
*/

#include "my.h"

int check_arg(char **argv)
{
    for (int i = 0; argv[1][i] != '\0'; i++)
        if (argv[1][i] < '0' || argv[1][i] > '9')
            return (1);
    for (int i = 0; argv[2][i] != '\0'; i++)
        if (argv[2][i] < '0' || argv[2][i] > '9')
            return (1);
    return (0);
}

int main(int argc, char **argv)
{
    if (argc == 3 && !check_arg(argv)) {
        int lines = my_atoi(argv[1]), nb = my_atoi(argv[2]), turn = 0;
        if (lines < 1 || lines > 100 || nb <= 0) return (84);
        char **map = create_map(lines);
        for (int i = 0; i != lines + 2; i++) my_printf("%s\n", map[i]);
        while (matches_number(map, lines) > 0) {
            if (turn == 0) {
                map = player_turn(map, lines * 2 - 1, &lines, nb), turn = 1;
                if (lines == -1) return (0);
            } else map = ai_turn(map, nb, lines), turn = 0;
            for (int i = 0; i != lines + 2; i++) my_printf("%s\n", map[i]);
        }
        for (int i = 0; map[i] != NULL; free(map[i]), i++);
        free(map);
        if (turn == 0) {
            my_printf("I lost... snif... but I'll get you next time!!\n");
            return (1);
        } else my_printf("You lost, too bad...\n");
        return (2);
    } else return (84);
}
