/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:56:19 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 16:13:31 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	cut_piece(t_piece *piece)
{
	int j;
	int i;

	j = piece->n - 1;
	i = piece->x - 1;
	piece->min.n = 0;
	piece->min.x = 0;
	while (j >= 0)
	{
		while (i >= 0)
		{
			if (piece->token[j][i] == '*')
			{
				if (piece->min.n <= j + 1)
					piece->min.n = j + 1;
				if (piece->min.x <= i + 1)
					piece->min.x =  i + 1;
			}
			i--;
		}
		i = piece->x - 1;
		j--;
	}
}

void get_piece(t_piece *piece)
{
	cut_piece(piece);
}