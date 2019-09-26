# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/26 17:09:24 by mmonahan          #+#    #+#              #
#    Updated: 2019/09/26 18:58:31 by mmonahan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = mmonahan.filler

SRC =  main.c \
		init_struct.c \
		get_size.c \
		get_player.c \
		get_plateau.c \
		get_piece.c \
		put_piece.c \
		heat_map.c \
		fill_map.c \
		get_next_line/get_next_line.c

HEADER = filler.h

FLAGS = -Wall -Werror -Wextra

OBJ = $(SRC:.c=.o)

all: $(OBJ) $(NAME)

$(NAME): $(OBJ)
		@echo "Сборка библиотеки libft.a"
		@make -C libft/ fclean && make -C libft/
		@gcc $(SRC) $(FLAGS) -o $(NAME) -L libft -lft
clean:
		@make -C libft/ clean
		@echo "Удаляем файлы компиляции"
		@rm -f $(OBJ)

fclean: clean
		@make -C libft/ fclean
		@echo "Удаляем $(NAME)"
		@rm -f $(NAME)

%.o: %.c $(HEADER)
		gcc $(FLAGS) -c $< -o $@

re: clean fclean
.PHONY: all clean fclean re
