##
## EPITECH PROJECT, 2020
## CPE_matchstick_2019
## File description:
## Makefile
##

NAME	=	matchstick

SRCS	=	main.c \
		create_map.c \
		player_turn.c \
		ai_turn.c \
		count_matches.c \
		my_atoi.c \
		get_next_line/get_next_line.c \

OBJS	=	$(SRCS:.c=.o)

CFLAGS =	-lmy -L./ -Wall -Wextra -g3 -O2

CALLMAKE =	cd my_printf/ && make

all:	$(NAME)

$(NAME):	$(OBJS) $(SRCS)
		$(CALLMAKE)
		gcc -o $(NAME) $(OBJS) $(CFLAGS)
clean:
		rm $(OBJS)
		cd my_printf/ && make clean
fclean:
		rm $(NAME)
		rm $(OBJS)
		cd my_printf/ && make fclean

re: fclean all
