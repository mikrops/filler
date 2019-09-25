/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_struct.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 15:25:02 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/25 15:57:51 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	init_point(t_point *point)
{
	point->n = -1;
	point->x = -1;
}

void	init_player(t_player *player)
{
	player->number = 0;
	player->o = 0;
	player->x = 0;
}

void	init_plateau(t_plateau *plateau)
{
	plateau->n = 0;
	plateau->x = 0;
	plateau->board = NULL;
	plateau->heatmap = NULL;
}

void	init_piece(t_piece *piece)
{
	piece->n = 0;
	piece->x = 0;
	piece->sum = 0;
	piece->min.n = 0;
	piece->min.x = 0;
	piece->token = NULL;
}

void	init_struct(t_point *pnt, t_player *plr, t_plateau *plt, t_piece *pc)
{
	init_point(pnt);
	init_player(plr);
	init_plateau(plt);
	init_piece(pc);
}
