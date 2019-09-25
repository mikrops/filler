/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 13:10:44 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/25 18:15:57 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Проверка позиции
*/

int		check_position(t_plateau *plateau, t_piece *piece, int row, int col)
{
	if (row + piece->min.n > plateau->n || col + piece->min.x > plateau->x)
		return (0);
	else
		return (1);
}

/*
**	сранивать все *
*/

int		check_token(t_plateau *plateau, t_piece *piece, int row, int col)
{
	int i;
	int j;
	int sum;
	int overlap;

	i = -1;
	j = -1;
	sum = 0;
	overlap = 0;
	while (++j < piece->min.n)
	{
		while (++i < piece->min.x)
			if (piece->token[j][i] == '*')
			{
				if (plateau->heatmap[row + j][col + i] == -2)
					overlap++;
				if (plateau->heatmap[row + j][col + i] == -1 || overlap > 1)
					return (-2);
				if (plateau->heatmap[row + j][col + i] != -2)
					sum += plateau->heatmap[row + j][col + i];
			}
		i = -1;
	}
	return (overlap == 1 ? sum : -1);
}

/*
**	Определяем место для вставки токена
*/

void	put_piece(t_plateau *plateau, t_piece *piece, t_point *point)
{
	int i;
	int j;
	int min;

	i = 0;
	j = 0;
	min = 9999999;
	while (j < plateau->n)
	{
		while (i < plateau->x)
		{
			piece->sum = check_position(plateau, piece, j, i) ?
					check_token(plateau, piece, j, i) : -3;
			if (piece->sum >= 0 && min > 0 && piece->sum <= min)
			{
				min = piece->sum;
				point->n = j;
				point->x = i;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
