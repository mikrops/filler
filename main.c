/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:27:34 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/21 21:02:12 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int		fd; // для проверки, потом убрать!!!
int		check = 1; // активировать проверки, потом убрать
void	print_matrix(char **matrix, int row, int col); // для теста, потмо убрать


/*
**	Выделяем область памяти для матрицы[row][col]
*/
char	**creat_matrix(int row, int col)
{
	char **matrix;
	int i;

	i = 0;
	matrix = (char **)ft_memalloc(sizeof(char *) * (row + 1));
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
		player->x = -1;
		player->n = -1;
	}
	else if (str[10] == '2')
	{
		player->number = 2;
		player->x = -2;
		player->n = -2;
	}
}


/*
**	Заполняем карту
*/
void	aggregate_plateau(t_plateau *plateau, int step)
{
	char	*str;

	str = ft_memalloc(1);
	if (step)
		get_next_line(0, &str);// пропускаем строку с номерами столбцов
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
		t_point		point;
		char		*str;
		char		*stop = "qq";

		int i = 1;
		str = "abc";
		player.x = 'X';
		player.n = 'x';

		fd = open("test.txt", O_WRONLY);

		player_definition(&player); // определяем номер игрока

		get_coordinates(&plateau.n, &plateau.x);// определяем размер для поля по первой строке
		plateau.board = creat_matrix(plateau.n, plateau.x); // выделяем память под двумерный массив в plateau.board
		aggregate_plateau(&plateau, FIRST_STEP); //заполнение двумерного массива


		get_coordinates(&piece.n, &piece.x);// определяем размер токена по первой строке
		piece.token = creat_matrix(piece.n, piece.x); // выделяем память под двумерный массив в piece.token
		//							// освобождаем память двумерного массива фигуры
		fill_matrix(piece.token, piece.n, piece.x);// за массив фигуры

		// создание тепловой карты
		heat_map(&plateau, &piece, &player);
		insert_piece(&plateau, &piece, &point);
		if (1)
		{
			if (check) // проверка на игрока
			{
				ft_putstr_fd("->player ", fd);
				ft_putnbr_fd(player.number, fd);
				ft_putstr_fd("<-\n", fd);
			}
			if (1) // проверка на координаты доски
			{
				ft_putstr_fd("->plateau N - ", fd);
				ft_putnbr_fd(plateau.n, fd);
				ft_putstr_fd("<-\n->plateau X - ", fd);
				ft_putnbr_fd(plateau.x, fd);
				ft_putstr_fd("<-\n", fd);
			}
			if (1) //вывод карты
				print_matrix(plateau.board, plateau.n, plateau.x);

			if (1) // проверка на координаты токена
			{
				ft_putstr_fd("->piece N - ", fd);
				ft_putnbr_fd(piece.n, fd);
				ft_putstr_fd("<-\n->piece X - ", fd);
				ft_putnbr_fd(piece.x, fd);
				ft_putstr_fd("<-\n", fd);
			}
			if (1) //вывод токена
				print_matrix(piece.token, piece.n, piece.x);

		}
		while (1)
		{

			//get_next_line(0, &str);

			if (!ft_strcmp(str, stop))
				return (1);

			//читаем строку
//			if (str[0] == '$')
//				; //определяем игрока
//			else if (str[1] == 'l')
//				; // обрабатываем карту
//			else if (str[2] == 'i')
//				; // определяем фигуру
//			// вычисляем координаты и выводим результат
//			ft_putstr_fd(str, fd);
//			ft_putstr_fd("\n", fd);
			//write(1, "8 1\n", 4);





//			aggregate_plateau(&plateau, OTHER_STEPS); //заполнение двумерного массива
//			//fill_matrix(plateau.board, plateau.n, plateau.x);
//
//			get_coordinates(&piece.n, &piece.x);// определяем размер токена по первой строке
//			piece.token = creat_matrix(piece.n, piece.x); // выделяем память под двумерный массив в piece.token
//			//							// освобождаем память двумерного массива фигуры
//			fill_matrix(piece.token, piece.n, piece.x);// за массив фигуры
//
//			// создание тепловой карты
//			heat_map(&plateau, &piece, &player);
			insert_piece(&plateau, &piece, &point);


			// ПРОПУСТИТЬ ДВЕ СТРОКИ А НЕ ОДНУ КОГДА ЗАПОЛНЯЮ ДОСКУ!!!

			ft_putnbr_fd(point.n, 1);
			ft_putchar_fd(' ', 1);
			ft_putnbr_fd(point.x, 1);
			ft_putchar_fd('\n', 1);

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

