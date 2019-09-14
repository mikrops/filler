/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:27:34 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/14 19:04:06 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		fd; // для проверки, потом убрать!!!
int		check = 1; // активировать проверки, потом убрать
void	print_matrix(char **matrix, int row, int col); // для теста, потмо убрать
void	print_heatmap(int **heatmap, int row, int col);

/*
**	Выделяем область памяти для матрицы[row][col]
*/
char	**creat_matrix(int row, int col)
{
	char **matrix;
	int i;

	i = 0;
	matrix = (char **)ft_memalloc(sizeof(char *) * row + 1);
	matrix[row] = NULL;
	while (i < row)
	{
		matrix[i] = (char *)ft_memalloc(sizeof(char) * col + 1);
		matrix[i][col] = '\0';
		i++;
	}
	return (matrix);
}
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
**	Определяем номер игрока
*/
void	player_definition(t_player *player)
{
	char *str;

	get_next_line(0, &str);
	if (str[10] == '1')
	{
		player->number = 1;
		player->x = 'O';
		player->n = 'o';
	}
	else if (str[10] == '2')
	{
		player->number = 2;
		player->x = 'X';
		player->n = 'x';
	}
}


/*
**	Заполняем карту
*/
void	aggregate_plateau(t_plateau *plateau)
{
	char	*str;

	str = ft_memalloc(1);
	get_next_line(0, &str);// пропускаем строку с номерами столбцов
	free(str);
	fill_matrix(plateau->board, plateau->n, plateau->x);
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
		char		*str;
		char		*stop = "qq";

		str = "abc";
		player.x = 'X';
		player.n = 'x';

		fd = open("test.txt", O_WRONLY);

		player_definition(&player); // определяем номер игрока


		get_coordinates(&plateau.n, &plateau.x);// определяем размер для поля по первой строке
		plateau.board = creat_matrix(plateau.n, plateau.x); // выделяем память под двумерный массив в board.board
		aggregate_plateau(&plateau); //заполнение двумерного массива


		get_coordinates(&piece.n, &piece.x);// определяем размер токена по первой строке
		piece.token = creat_matrix(piece.n, piece.x); // выделяем память под двумерный массив в board.board
		//aggregate_piece(&piece);
		fill_matrix(piece.token, piece.n, piece.x);

		// создание тепловой карты
		heat_map(&plateau, piece, player);

		if (1)
		{
			if (check) // проверка на игрока
			{
				ft_putstr_fd("->player ", fd);
				ft_putnbr_fd(player.number, fd);
				ft_putstr_fd("<-\n", fd);
			}
			if (check) // проверка на координаты доски
			{
				ft_putstr_fd("->plateau по N - ", fd);
				ft_putnbr_fd(plateau.n, fd);
				ft_putstr_fd("<-\n->plateau по X - ", fd);
				ft_putnbr_fd(plateau.x, fd);
				ft_putstr_fd("<-\n", fd);
			}
			if (check)
				print_matrix(plateau.board, plateau.n, plateau.x); //вывод карты

			if (check) // проверка на координаты токена
			{
				ft_putstr_fd("->piece по N - ", fd);
				ft_putnbr_fd(piece.n, fd);
				ft_putstr_fd("<-\n->piece по X - ", fd);
				ft_putnbr_fd(piece.x, fd);
				ft_putstr_fd("<-\n", fd);
			}
			if (check)
				print_matrix(piece.token, piece.n, piece.x); //вывод токена
			if (check)
				print_heatmap(plateau.heatmap, plateau.n, plateau.x); //вывод тепловой
		}
		while (1)
		{

			//get_next_line(0, &str);

			if (!ft_strcmp(str, stop))
				return (1);
			//читаем строку
			if (str[0] == '$')
				; //определяем игрока
			else if (str[1] == 'l')
				; // обрабатываем карту
			else if (str[2] == 'i')
				; // определяем фигуру
			// вычисляем координаты и выводим результат
			write(1, "8 1\n", 4);

			//один раз--
			//поймать игрока-++++++++++
			//поймать размер карты-+++++++++
			//замолочить карту-+++++++++
			//залить карту
			// - пропустить -одну- строку
			// - залить карту
			//поймать размер токена
			//замалочить токен
			//залить токен
			//-выдать ответ-

			//много раз--
			//залить карту
			// - пропустить -две- строки
			// - залить карту
			//поймать размер токена
			//перемалочить токен
			//залить токен
			//-выдать ответ-


		}
		close(fd);
	}
	return 0;
}


/*
**	Выводим в файл test.txt карту
*/

void	print_matrix(char **matrix, int row, int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr_fd("---+------------+----------+---\n", fd);
	while (j < row)
	{
		while (i < col)
		{
			ft_putchar_fd(matrix[j][i], fd);
			i++;
		}
		ft_putstr_fd("\n", fd);
		i = 0;
		j++;
	}
	ft_putstr_fd("---+------------+----------+---\n", fd);
}

void	print_heatmap(int **heatmap, int row, int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr_fd("---+------------+----------+---\n", fd);
	while (j < row)
	{
		while (i < col)
		{
			ft_putnbr_fd(heatmap[j][i], fd);
			i++;
		}
		ft_putstr_fd("\n", fd);
		i = 0;
		j++;
	}
	ft_putstr_fd("---+------------+----------+---\n", fd);
}