/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:27:34 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/04 20:43:59 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int main()
{
	if (1)
	{
		t_player 	p;
		int			i;
		char		*str;
		char		*stop = "Phibonacci: error: invalid map";
		char		*p1 = "$$$ exec p1 : [players/mmonahan.filler]";
		char		*p2 = "$$$ exec p2 : [players/mmonahan.filler]";

		str = "abc";
		p.last = 0;
		p.first = 0;
		while (ft_strcmp(str, stop)) //(i > 0)
		{
			i = get_next_line(0, &str);
			if (!ft_strcmp(str, p1))
			{
				p.first = 'O';
				p.last = 'o';
			}
			else if (!ft_strcmp(str, p2))
			{
				p.first = 'X';
				p.last = 'x';
			}
			printf("gnl = %d\t **line = %s\n", i, str);
		}
	}

	return 0;
}
