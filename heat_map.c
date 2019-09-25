/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:08:55 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/25 14:53:00 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Установка чисел на 1 больше крестом
*/

int		put_digit_cross(t_plateau *plateau, int row, int col, int find)
{
	int flag;

	flag = 0;
	if (row + 1 < plateau->n && plateau->heatmap[row + 1][col] == 0)
	{
		plateau->heatmap[row + 1][col] = find + 1;
		flag = 1;
	}
	if (row - 1 >= 0 && plateau->heatmap[row - 1][col] == 0)
	{
		plateau->heatmap[row - 1][col] = find + 1;
		flag = 1;
	}
	if (col + 1 < plateau->x && plateau->heatmap[row][col + 1] == 0)
	{
		plateau->heatmap[row][col + 1] = find + 1;
		flag = 1;
	}
	if (col - 1 >= 0 && plateau->heatmap[row][col - 1] == 0)
	{
		plateau->heatmap[row][col - 1] = find + 1;
		flag = 1;
	}
	return (flag);
}

/*
**	Установка чисел на 1 больше диагональю
*/

void	put_digit_diagonal(t_plateau *plateau, int row, int col, int find)
{
	if (row + 1 < plateau->n && col + 1 < plateau->x &&
		plateau->heatmap[row + 1][col + 1] == 0)
		plateau->heatmap[row + 1][col + 1] = find + 1;
	if (row - 1 >= 0 && col - 1 >= 0 &&
		plateau->heatmap[row - 1][col - 1] == 0)
		plateau->heatmap[row - 1][col - 1] = find + 1;
	if (row - 1 >= 0 && col + 1 < plateau->x &&
		plateau->heatmap[row - 1][col + 1] == 0)
		plateau->heatmap[row - 1][col + 1] = find + 1;
	if (row + 1 < plateau->n && col - 1 >= 0 &&
		plateau->heatmap[row + 1][col - 1] == 0)
		plateau->heatmap[row + 1][col - 1] = find + 1;
}

/*
**	Установка '1' вокруг врага
*/

void	fill_heatmap(t_plateau *plateau)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (j < plateau->n)
	{
		while (i < plateau->x)
		{
			if (plateau->heatmap[j][i] == -1)
			{
				put_digit_cross(plateau, j, i, 0);
				put_digit_diagonal(plateau, j, i, 0);
			}
			i++;
		}
		i = 0;
		j++;
	}
}

/*
**	заполнение тепловой карты
*/

void	fill_heatmap_full(t_plateau *plateau)
{
	int	i;
	int j;
	int dot;
	int flag;

	dot = 1;
	flag = 1;
	while (flag)
	{
		i = 0;
		j = 0;
		flag = 0;
		while (j < plateau->n)
		{
			while (i < plateau->x)
			{
				if (plateau->heatmap[j][i] == dot)
					flag += put_digit_cross(plateau, j, i, dot);
				i++;
			}
			i = 0;
			j++;
		}
		dot++;
	}
}

/*
**	теловая карта
*/

void	heat_map(t_plateau *plateau, t_player *player)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!plateau->heatmap)
		plateau->heatmap = ft_map_int(plateau->n, plateau->x);
	while (j < plateau->n)
	{
		while (i < plateau->x)
		{
			if (plateau->board[j][i] == 'O' || plateau->board[j][i] == 'o')
				plateau->heatmap[j][i] = player->o;
			if (plateau->board[j][i] == 'X' || plateau->board[j][i] == 'x')
				plateau->heatmap[j][i] = player->x;
			if (plateau->board[j][i] == '.')
				plateau->heatmap[j][i] = 0;
			i++;
		}
		i = 0;
		j++;
	}
	fill_heatmap(plateau);
	fill_heatmap_full(plateau);
}
