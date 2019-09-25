/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_player.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/24 20:37:42 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 20:52:54 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Определяем номер игрока по первой строке
*/

void	player_definition(t_player *player)
{
	char *str;

	get_next_line(0, &str);
	if (player->o == 0 && player->x == 0)
	{
		if (str[10] == '1')
		{
			player->number = 1;
			player->x = -1;
			player->o = -2;
		}
		else if (str[10] == '2')
		{
			player->number = 2;
			player->x = -2;
			player->o = -1;
		}
	}
	free(str);
}

/*
**	Получаем данные игроков
*/

void	get_player(t_player *player)
{
	player_definition(player);
}
