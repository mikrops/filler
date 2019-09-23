/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:27:34 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/23 16:07:44 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		fd; // для проверки, потом убрать!!!
int		check = 1; // активировать проверки, потом убрать
//void	ft_put_map_chr_fd(char **map, int row, int col, int fd); // для теста, потмо убрать

/*
**	Заполнение матрицы[row][col] из потока 0
*/
void	fill_matrix(char **matrix, int row, int col)
{
	char	*str;
	int		i;
	int		j;
	int		shift;

	str = ft_memalloc(1);
	i = 0;
	j = 0;
	shift = 0;
	while (j < row)
	{
		get_next_line(0, &str);

		while (ft_isdigit(str[shift]) || ft_isspace(str[shift]))
			shift++;
		while (i < col)
		{
			matrix[j][i] = str[i + shift];
			i++;
		}
		i = 0;
		j++;
		shift = 0;
	}
}

/*
**	Определяем номер игрока по первой строке
*/
void	player_definition(t_player *player)
{
	char *str;

	get_next_line(0, &str);
	if (player->n == 0 && player->x == 0)
	{
		if (str[10] == '1')
		{
			player->number = 1;
			player->x = -1;
			player->n = -1;
		} else if (str[10] == '2')
		{
			player->number = 2;
			player->x = -2;
			player->n = -2;
		}
	}
}

/*
**	Заполняем карту поля
*/
void	aggregate_plateau(t_plateau *plateau, int step)
{
	char	*str;

	str = ft_memalloc(1);
	get_next_line(0, &str);// пропускаем строку с номерами столбцов
	free(str);
	fill_matrix(plateau->board, plateau->n, plateau->x);
}

/*
**	Заполняем карту фигуры
*/
void	aggregate_piece(t_piece *piece)
{
	fill_matrix(piece->token, piece->n, piece->x);
}

/*
**	Определяем размеры фигуры по первой строке
*/
void	get_coordinates(int *n, int *x)
{
	char	*str;

	get_next_line(0, &str);
	while (ft_isalpha(*str) || ft_isspace(*str))
		str++;
	*n = ft_atoi(str);
	while (ft_isdigit(*str))
		str++;
	while (ft_isspace(*str))
		str++;
	*x = ft_atoi(str);
}

/*
**	Галвная
*/
int main()
{
	if (1)
	{
		t_player 	player;
		t_plateau	plateau;
		t_piece		piece;
		t_point		point;
		char		*str;
		char		*stop = "qq";

		str = "abc";
		player.x = 0;
		player.n = 0;

		fd = open("test.txt", O_WRONLY);

		player_definition(&player); //определяем номер игрока


		if (1)
		{
			if (check) // проверка на игрока
			{
				ft_putstr_fd("->player ", fd);
				ft_putnbr_fd(player.number, fd);
				ft_putstr_fd("<-\n", fd);
			}
		}
		while (1)
		{

			//get_next_line(0, &str);

			if (!ft_strcmp(str, stop))
				return (1);


			get_coordinates(&plateau.n, &plateau.x);// 1 определяем размер для поля по первой строке
			plateau.board = ft_map_char(plateau.n, plateau.x); // 0 выделяем память для plateau.board
			aggregate_plateau(&plateau, FIRST_STEP); // 1(8) или 2(8) заполнение двумерного массива


			get_coordinates(&piece.n, &piece.x);// 1 определяем размер токена по первой строке
			piece.token = ft_map_char(piece.n, piece.x); // 0 выделяем память для piece.token
			aggregate_piece(&piece); // 1(8) заполнение двумерного массива



			// создание тепловой карты
			heat_map(&plateau, &piece, &player);
			insert_piece(&plateau, &piece, &point);

			if (1)
			{
				if (check) // проверка на координаты доски
				{
					ft_putstr_fd("->plateau N - ", fd);
					ft_putnbr_fd(plateau.n, fd);
					ft_putstr_fd("<-\n->plateau X - ", fd);
					ft_putnbr_fd(plateau.x, fd);
					ft_putstr_fd("<-\n", fd);
				}
				if (check) //вывод карты
				{
					ft_putstr_fd("---+------------+----------+---\n", fd);
					ft_put_map_chr_fd(plateau.board, plateau.n, plateau.x, fd);
					ft_putstr_fd("---+------------+----------+---\n", fd);
				}

				if (check) // проверка на координаты токена
				{
					ft_putstr_fd("->piece N - ", fd);
					ft_putnbr_fd(piece.n, fd);
					ft_putstr_fd("<-\n->piece X - ", fd);
					ft_putnbr_fd(piece.x, fd);
					ft_putstr_fd("<-\n", fd);
				}
				if (check) //вывод токена
				{
					ft_putstr_fd("---+------------+----------+---\n", fd);
					ft_put_map_chr_fd(piece.token, piece.n, piece.x, fd);
					ft_putstr_fd("---+------------+----------+---\n", fd);
				}
			}

			print_answer(&point);

		}
		close(fd);
	}
	return 0;
}
