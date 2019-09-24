/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:08:55 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 20:03:36 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


int		fd_hm; // для проверки, потом убрать!!!

/*
**	Заполнение матрицы[row][col] из матрицы[row][col]
*/

void	init_heatmap(t_plateau *plateau, t_player *player)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < plateau->n)
	{
		while (i < plateau->x)
		{
			if (player->number == 1)
			{
				if (plateau->board[j][i] == 'O' || plateau->board[j][i] == 'o')
					plateau->heatmap[j][i] = -2;
				if (plateau->board[j][i] == 'X' || plateau->board[j][i] == 'x')
					plateau->heatmap[j][i] = -1;
			}
			else
			{
				if (plateau->board[j][i] == 'O' || plateau->board[j][i] == 'o')
					plateau->heatmap[j][i] = -1;
				if (plateau->board[j][i] == 'X' || plateau->board[j][i] == 'x')
					plateau->heatmap[j][i] = -2;
			}
			if (plateau->board[j][i] == '.')
				plateau->heatmap[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}
}

/*
** Установка чисел на 1 больше крестом
*/

int		insert_digit_cross(t_plateau *plateau, int **heatmap, int row, int col, int find)
{
	int flag;

	flag = 0;
	if (row + 1 < plateau->n && heatmap[row + 1][col] == 0)
	{
		heatmap[row + 1][col] = find + 1;
		flag = 1;
	}
	if (row - 1 >= 0 && heatmap[row - 1][col] == 0)
	{
		heatmap[row - 1][col] = find + 1;
		flag = 1;
	}
	if (col + 1 < plateau->x && heatmap[row][col + 1] == 0)
	{
		heatmap[row][col + 1] = find + 1;
		flag = 1;
	}
	if (col - 1 >= 0 && heatmap[row][col - 1] == 0)
	{
		heatmap[row][col - 1] = find + 1;
		flag = 1;
	}
	return  (flag);
}

/*
** Установка чисел на 1 больше диагональю
*/

void	insert_digit_diagonal(t_plateau *plateau, int **heatmap, int row, int col, int find)
{
	if (row + 1 < plateau->n && col + 1 < plateau->x && heatmap[row + 1][col + 1] == 0)
		heatmap[row + 1][col + 1] = find + 1;
	if (row - 1 >= 0 && col - 1 >= 0 && heatmap[row - 1][col - 1] == 0)
		heatmap[row - 1][col - 1] = find + 1;
	if (row - 1 >= 0 && col + 1 < plateau->x && heatmap[row - 1][col + 1] == 0)
		heatmap[row - 1][col + 1] = find + 1;
	if (row + 1 < plateau->n && col - 1 >= 0 && heatmap[row + 1][col - 1] == 0)
		heatmap[row + 1][col - 1] = find + 1;

}

/*
** Установка '1' вокруг врага
*/

void	fill_heatmap(t_plateau *plateau, int **heatmap, int row, int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < row)
	{
		while (i < col)
		{
			if (heatmap[j][i] == -1)
			{
				insert_digit_cross(plateau, heatmap, j, i, 0);
				insert_digit_diagonal(plateau, heatmap, j, i, 0);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

/*
** заполнение тепловой карты
*/

void	fill_heatmap_full(t_plateau *plateau, int **heatmap, int row, int col)
{
	int i;
	int j;
	int dot;
	int flag;

	i = 0;
	j = 0;
	dot = 1;
	flag = 1;
	while (flag)
	{
		flag = 0;
		while (j < row)
		{
			while (i < col)
			{
				if (heatmap[j][i] == dot)
					flag += insert_digit_cross(plateau, heatmap, j, i, dot);
				i++;
			}
			i = 0;
			j++;
		}
		dot++;
		j = 0;
		i = 0;
	}
	if (1)
	{
		ft_putstr_fd("---+------------+----------+---\n", fd_hm);
		ft_put_map_int_fd(plateau->heatmap, plateau->n, plateau->x, fd_hm);
		ft_putstr_fd("---+------------+----------+---\n", fd_hm);
	}
}

/*
**	теловая карта
*/

void	heat_map(t_plateau *plateau, t_player *player)
{
	fd_hm = open("./logs/test_hm.txt", O_WRONLY);
	if (!plateau->heatmap)
	{
		plateau->heatmap = ft_map_int(plateau->n, plateau->x);
	}
	init_heatmap(plateau, player);

	//заполнение первого куска
	fill_heatmap(plateau, plateau->heatmap, plateau->n, plateau->x);

	//заполнение всей
	fill_heatmap_full(plateau, plateau->heatmap, plateau->n, plateau->x);

	close(fd_hm);
}
