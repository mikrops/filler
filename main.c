/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:27:34 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/09 21:04:47 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#include <stdio.h>

int fd; // для проверки, потом убрать!!!

int player_definition(t_player plr, char *str)
{
	if (str[10] == '1')
	{
		plr.first = 'O';
		plr.last = 'o';
		write(fd, "->player 1<-", 12);
		write(fd, "\n", 1);
	}
	else if (str[10] == '2')
	{
		plr.first = 'X';
		plr.last = 'x';
		write(fd, "->player 2<-", 12);
		write(fd, "\n", 1);
	}
	return (0);
}

int plateau_definition(t_plateau plt, char *str)
{
	int i;

	i = 0;
	plt.n = 0;
	plt.x = 0;

	if (str[0] == 'P' && str[1] == 'l')
	{
		str += 8;
		while (*str && *str != ' ')
		{
			if (ft_isdigit(*str))
				plt.n = plt.n * 10 + *str - '0';
			str++;
		}
		while (*str)
		{
			if (ft_isdigit(*str))
				plt.x = plt.x * 10 + *str - '0';
			str++;
		}


		ft_putstr_fd("->по N - ", fd);
		ft_putnbr_fd(plt.n, fd);
		ft_putstr_fd("<-\n->по X - ", fd);
		ft_putnbr_fd(plt.x, fd);
		ft_putstr_fd("<-\n", fd);

		if (plt.flag == 0)
		{
			plt.plateau = (char **) malloc(sizeof(char *) * plt.n + 1);
			while (i < plt.n)
			{
				plt.plateau[i] = (char) malloc(sizeof(char) * plt.x + 1);
				i++;
			}
			plt.flag = 1;
		}

		//заполнение plt.plateau
//		get_next_line(0, &str);// пропускаем строку с номерами столбцов
//		i = 0;
//		int j = 0;
//		while (j < plt.n)
//		{
//			get_next_line(0, &str);
//			while (*str != ' ')
//				str++;
//			str++;
//			while (i < plt.x)
//			{
//				plt.plateau[j][i] = *str;
//				i++;
//			}
//			i = 0;
//			j++;
//		}


		//вывод проверка plt.plateau

//		i = 0;
//		j = 0;
//		while (j < plt.n)
//		{
//			ft_putstr_fd("-->", fd);
//			while (i < plt.x)
//			{
//				ft_putchar_fd(plt.plateau[j][i], fd);
//				i++;
//			}
//			i = 0;
//			j++;
//			ft_putstr_fd("<--\n", fd);
//		}


	}
	return (0);
}

int piece_definition(t_piece pc, char *str)
{

	return (0);
}


int main()
{
	if (1)
	{
		t_player 	p;
		t_plateau	plt;
		int			i;
		char		*str;
		//int			fd; //пока есть глобальная, но потом она уйдет она для проверки
		char		*stop = "Phibonacci: error: invalid map";

		str = "abc";
		p.first = 'X';
		p.last = 'x';
		plt.flag = 0;

		fd = open("test.txt", O_WRONLY);
		get_next_line(0, &str);
		player_definition(p, str);

		while (1)
		{
			get_next_line(0, &str);

			i = ft_strlen(str);
			if (!ft_strcmp(str, stop))
				return (1);

			plateau_definition(plt, str);

			write(1, "8 2\n", 4);
			write(fd, str, i);
			write(fd, "\n", 1);
		}
		close(fd);
	}

	return 0;
}
