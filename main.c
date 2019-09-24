/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:27:34 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 20:03:36 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fd; // для проверки, потом убрать!!!
int		check = 1; // активировать проверки, потом убрать

/*
**	Заполнение матрицы[row][col] из потока 0
*/
void	fill_matrix(char **matrix, int row, int col)
{
	char	*str;
	int		i;
	int		j;
	int		shift;

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
		free(str);
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

	if (step)
		;

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

		player.x = 0;
		player.n = 0;

		fd = open("./logs/test.txt", O_WRONLY);

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
			get_coordinates(&plateau.n, &plateau.x);// 1 определяем размер для поля по первой строке
			plateau.board = ft_map_char(plateau.n, plateau.x); // 0 выделяем память для plateau.board
			aggregate_plateau(&plateau, 0); // 1(8) или 2(8) заполнение двумерного массива

			get_coordinates(&piece.n, &piece.x);// 1 определяем размер токена по первой строке
			piece.token = ft_map_char(piece.n, piece.x); // 0 выделяем память для piece.token
			aggregate_piece(&piece); // 1(8) заполнение двумерного массива
			get_piece(&piece);

			// создание тепловой карты
			heat_map(&plateau, &player);
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

					ft_putstr_fd(" [", fd);
					ft_putnbr_fd(piece.min.n, fd);

					ft_putstr_fd("]<-\n->piece X - ", fd);
					ft_putnbr_fd(piece.x, fd);

					ft_putstr_fd(" [", fd);
					ft_putnbr_fd(piece.min.x, fd);

					ft_putstr_fd("]<-\n", fd);
				}
				if (check) //вывод токена
				{
					ft_putstr_fd("---+------------+----------+---\n", fd);
					ft_put_map_chr_fd(piece.token, piece.n, piece.x, fd);
					ft_putstr_fd("---+------------+----------+---\n", fd);
				}
			}

			ft_map_chr_del(piece.token, piece.n); //фришим токен
			print_answer(&point);

			if (point.n < 0 && point.x < 0)
			{
				ft_map_int_del(plateau.heatmap, plateau.n);
				ft_map_chr_del(plateau.board, plateau.n);
				break ;
			}
		}
		close(fd);
	}
	return 0;
}
