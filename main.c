/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:27:34 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/05 21:00:24 by mmonahan         ###   ########.fr       */
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
		char		*p1 = "$$$ exec p1 : [./mmonahan.filler]";

		str = "abc";
		p.first = 'X';
		p.last = 'x';
		while (1)//(ft_strcmp(str, stop)) //(i > 0)
		{
			i = get_next_line(0, &str);
			if (!ft_strcmp(str, stop))
				return (1);
			if (!ft_strcmp(str, p1))
			{
				p.first = 'O';
				p.last = 'o';
			}

			//printf("gnl = %d\t **line = %s\n", i, str);
			write(1, "8 2\n", 4);
		}
	}

	return 0;
}
