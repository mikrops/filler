/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/14 17:08:55 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/17 20:49:19 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"


int		fd_hm; // для проверки, потом убрать!!!
void	print_heatmap(int **heatmap, int row, int col);

/*
**	Выделяем область памяти для матрицы[row][col]
*/

int	**creat_heatmap(int row, int col)
{
	int **heatmap;
	int i;
	ft_putstr_fd("creat_heatmap\n", fd_hm);
	i = 0;
	heatmap = (int **)ft_memalloc(sizeof(int *) * row + 1);
	while (i < row)
	{
		heatmap[i] = (int *)ft_memalloc(sizeof(int) * col + 1);
		i++;
	}

	return (heatmap);
}

/*
**	Заполнение матрицы[row][col] из потока 0
*/

void	fill_heatmap(t_plateau *plateau, t_player player)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (j < plateau->n)
	{
		while (i < plateau->x)
		{
			if (player.number == 1)
			{
				if (plateau->board[j][i] == 'O' || plateau->board[j][i] == 'o')
					plateau->heatmap[j][i] = 0;
				if (plateau->board[j][i] == 'X' || plateau->board[j][i] == 'x')
					plateau->heatmap[j][i] = 9;
			}
			else
			{
				if (plateau->board[j][i] == 'O' || plateau->board[j][i] == 'o')
					plateau->heatmap[j][i] = 9;
				if (plateau->board[j][i] == 'X' || plateau->board[j][i] == 'x')
					plateau->heatmap[j][i] = 0;
			}
			if (plateau->board[j][i] == '.')
				plateau->heatmap[j][i] = 1;
			i++;
		}
		i = 0;
		j++;
	}
}


/*
**	теловая карта
*/

void heat_map(t_plateau *plateau, t_piece piece, t_player player)
{
	fd_hm = open("test_hm.txt", O_WRONLY);
	if (!plateau->heatmap)
	{
		plateau->heatmap = creat_heatmap(plateau->n, plateau->x);
	}
	fill_heatmap(plateau, player);

	if (piece.x)
		;

	if (1) //вывод тепловой
		print_heatmap(plateau->heatmap, plateau->n, plateau->x);

	close(fd_hm);

}

void	print_heatmap(int **heatmap, int row, int col)
{
	int i;
	int j;

	i = 0;
	j = 0;
	ft_putstr_fd("---+------------+----------+---\n", fd_hm);
	while (j < row)
	{
		while (i < col)
		{
			ft_putnbr_fd(heatmap[j][i], fd_hm);
			i++;
		}
		ft_putstr_fd("\n", fd_hm);
		i = 0;
		j++;
	}
	ft_putstr_fd("---+------------+----------+---\n", fd_hm);
}