/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_piece.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/19 17:56:44 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/20 18:40:22 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fd_ip; // для проверки, потом убрать!!!

/*
**	сранивать все *:
**					-2 должен быть один раз!
**					-1 ни одного раза!
**		тогда:	считаем сумму цыфр где есть *
**		иначе:	идем дальше
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
	ft_putstr_fd("\tcheck_token_in_board - ENTER!\n", fd_ip);
	if (row + piece->n > plateau->n || col + piece->x > plateau->x)
	{
		ft_putstr_fd("\t\tcheck_token_in_board - ERROR -3!\n", fd_ip);
		return (-3);
	}
	while (j < piece->n)
	{
		while (i < piece->x)
		{
			if (1)
			{
				ft_putstr_fd("\t\ttoken ", fd_ip);
				ft_putnbr_fd(j, fd_ip);
				ft_putchar_fd(' ', fd_ip);
				ft_putnbr_fd(i, fd_ip);
				ft_putstr_fd("\n", fd_ip);
			}
			if (plateau->heatmap[row + j][col + i] == -2 && piece->token[j][i] == '*')
			{
				ft_putstr_fd("\t\tcheck_token_in_board - overlap++!\n", fd_ip);
				overlap++;
			}
			else if (plateau->heatmap[row + j][col + i] == -1)
			{
				ft_putstr_fd("\t\tcheck_token_in_board - ERROR -2!\n", fd_ip);
				return (-2);
			}
			if (piece->token[j][i] == '*' && plateau->heatmap[row + j][col + i] != -2)
			{
				sum += plateau->heatmap[row + j][col + i];
			}
			if (overlap > 1)
			{
				ft_putstr_fd("\t\tcheck_token_in_board - ERROR -1!\n", fd_ip);
				return (-1);
			}
			i++;
		}
		i = 0;
		j++;
	}
	ft_putstr_fd("\t\tcheck_token_in_board - sum++!\t", fd_ip);
	ft_putnbr_fd(sum, fd_ip);
	ft_putchar_fd('\n', fd_ip);
	ft_putstr_fd("\tcheck_token_in_board - EXIT!\n", fd_ip);
	return (overlap == 1 ? sum : 0);
}

void	insert_piece(t_plateau *plateau, t_piece *piece, t_point *point)
{
	fd_ip = open("test_ip.txt", O_WRONLY);
	int i;
	int j;
	int min;
	int sum;

	i = 0;
	j = 0;
	min = 999999;
	sum = 0;
	point->n = 0;
	point->x = 0;
	while (j < plateau->n - piece->n)
	{
		while (i < plateau->x - piece->x)
		{
			if (1)
			{
				ft_putstr_fd("heatmap ", fd_ip);
				ft_putnbr_fd(j, fd_ip);
				ft_putchar_fd(' ', fd_ip);
				ft_putnbr_fd(i, fd_ip);
				ft_putstr_fd("\n", fd_ip);
			}
			sum = check_token_in_board(plateau, piece, j, i);
			if (sum > 0 && min > 0 && sum <= min)
			{
				ft_putstr_fd("insert_piece - 01 \n", fd_ip);
				min = sum;
				point->n = j;
				point->x = i;
				if (0)
				{
					ft_putstr_fd("min: ", fd_ip);
					ft_putnbr_fd(point->n, fd_ip);
					ft_putchar_fd(' ', fd_ip);
					ft_putnbr_fd(point->x, fd_ip);
					ft_putstr_fd("*****\n", fd_ip);
				}
			}
			i++;
		}
		i = 0;
		j++;
	}
	ft_putstr_fd("insert_piece - ******** \n", fd_ip);
	if (1)
	{
		ft_putstr_fd("ОТВЕТ: ", fd_ip);
		ft_putnbr_fd(point->n, fd_ip);
		ft_putchar_fd(' ', fd_ip);
		ft_putnbr_fd(point->x, fd_ip);
		ft_putstr_fd(" (", fd_ip);
		ft_putnbr_fd(min, fd_ip);
		ft_putstr_fd(")\n", fd_ip);
	}

	//write(1, "8 1\n", 4);

	close(fd_ip);
}