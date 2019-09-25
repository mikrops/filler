/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_plateau.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 11:39:41 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/25 12:54:25 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Заполняем карту поля
**	Важно! Есть затруднения с переменной step. Она не нужно, но без нее сига!
*/

void	fill_board(t_plateau *plateau, int step)
{
	char	*str;

	if (step)
		;
	str = ft_memalloc(1);
	get_next_line(0, &str);
	free(str);
	fill_map(plateau->board, plateau->n, plateau->x);
}

/*
**	Заполняем карту поля
*/

void	get_plateau(t_plateau *plateau)
{
	get_size(&plateau->n, &plateau->x);
	if (!plateau->board)
		plateau->board = ft_map_char(plateau->n, plateau->x);
	fill_board(plateau, 0);
}
