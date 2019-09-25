/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_piece.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 13:56:19 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/25 14:16:28 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Заполняем карту фигуры
*/

void	fill_token(t_piece *piece)
{
	fill_map(piece->token, piece->n, piece->x);
}

/*
**	Определяем минимальные размеры токена
*/

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
					piece->min.x = i + 1;
			}
			i--;
		}
		i = piece->x - 1;
		j--;
	}
}

/*
**	Получаем данные токена
*/

void	get_piece(t_piece *piece)
{
	get_size(&piece->n, &piece->x);
	piece->token = ft_map_char(piece->n, piece->x);
	fill_token(piece);
	cut_piece(piece);
}
