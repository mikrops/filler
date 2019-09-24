/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:56:44 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 18:18:27 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	сранивать все *
*/

int		check_token_in_board(t_plateau *plateau, t_piece *piece, int row, int col)
{
	int i;
	int j;
	int sum;
	int overlap;

	i = 0;
	j = 0;
	sum = 0;
	overlap = 0;
	if (row + piece->min.n > plateau->n || col + piece->min.x > plateau->x)
		return (-3);
	while (j < piece->min.n)
	{
		while (i < piece->min.x)
		{
			if (plateau->heatmap[row + j][col + i] == -2 && piece->token[j][i] == '*')
				overlap++;
			else if (plateau->heatmap[row + j][col + i] == -1)
				return (-2);
			if (piece->token[j][i] == '*' && plateau->heatmap[row + j][col + i] != -2)
				sum += plateau->heatmap[row + j][col + i];
			if (overlap > 1)
				return (-1);
			i++;
		}
		i = 0;
		j++;
	}
	return (overlap == 1 ? sum : -1);
}

void	insert_piece(t_plateau *plateau, t_piece *piece, t_point *point)
{
	int i;
	int j;
	int min;
	int sum;

	i = 0;
	j = 0;
	min = 999999;
	//sum = -1;
	point->n = -1;
	point->x = -1;
	while (j < plateau->n)// - piece->n)
	{
		while (i < plateau->x)// - piece->x)
		{
			sum = check_token_in_board(plateau, piece, j, i);
			if (sum >= 0 && min > 0 && sum <= min)
			{
				min = sum;
				point->n = j;
				point->x = i;
			}
			i++;
		}
		i = 0;
		j++;
	}
}
