# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/01/19 01:02:44 by mmonahan          #+#    #+#              #
#    Updated: 2019/02/13 20:19:35 by mmonahan         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ../libft/libft.a

all: $(NAME)

$(NAME):
		#мэйк библиотеки
		@make -C libft/ fclean && make -C libft/
		#добавляем в библиотеку gnl
		@clang -Wall -Wextra -Werror -I libft/includes -o get_next_line.o -c get_next_line.c
		#добавляем в библиотеку main
		@clang -Wall -Wextra -Werror -I libft/includes -o main.o -c main.c
		#компилируем test_gnl
		@clang -o test_gnl main.o get_next_line.o -I libft/includes -L libft/ -lft
		#запускаем test_gnl
		#@./test_gnl

clean:
		#удаляем файлы компиляции .gch
		@rm -f *.o
		@make -C libft/ clean

fclean: clean
		#удаляем main (убрать перед проверкой)
		@rm -f test_gnl
		@make -C libft/ fclean

re: fclean all
