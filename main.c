/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:27:34 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/04 18:21:02 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int main()
{
	printf("Hello, Mr.Filler!\n");
	if (1)
	{
		printf("\n---------TEST libft---------\n");
		char c = 'A';
		printf("ft_isalpha('%c') it's %s\n", c,
			   ft_isalpha(c) ? "true" : "false");
		printf("---------END TEST libft-----\n");
	}

	if (1)
	{
		printf("\n---------TEST get_next_line---------\n");
		int fd;
		char *str;
		int i;

		str = "abc";
		i = 1;
		fd = open("../test.txt", O_RDONLY);
		while (i > 0)
		{
			i = get_next_line(fd, &str);
			ft_putstr("gnl = ");
			ft_putnbr(i);
			ft_putstr("\t **line = ");
			ft_putstr(str);
			ft_putstr("\n");
		}
		close(fd);
		printf("---------END TEST get_next_line-----\n");
	}

	return 0;
}
