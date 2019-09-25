/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:27:34 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/25 13:15:56 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		fd; // для проверки, потом убрать!!!

void print_answer(t_point *point)
{
	if (point->n >= 0 && point->x >= 0)
	{
		ft_putnbr_fd(point->n, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(point->x, 1);
		ft_putchar_fd('\n', 1);
	}
	else
	{
		ft_putnbr_fd(0, 1);
		ft_putchar_fd(' ', 1);
		ft_putnbr_fd(0, 1);
		ft_putchar_fd('\n', 1);
	}
}

/*
**	Галвная
*/

int main()
{
	t_player 	player;
	t_plateau	plateau;
	t_piece		piece;
	t_point		point;

	fd = open("./logs/test.txt", O_WRONLY);
	get_player(&player); //определяем игрока и врага

	if (1) // проверка на игрока
	{
		ft_putstr_fd("->player ", fd);
		ft_putnbr_fd(player.number, fd);
		ft_putstr_fd("<-\n", fd);
	}
	while (1)
	{
		get_plateau(&plateau);
		get_piece(&piece);

		// создание тепловой карты
		heat_map(&plateau, &player);
		put_piece(&plateau, &piece, &point);

		if (1)
		{
			if (1) // проверка на координаты доски
			{
				ft_putstr_fd("->plateau N - ", fd);
				ft_putnbr_fd(plateau.n, fd);
				ft_putstr_fd("<-\n->plateau X - ", fd);
				ft_putnbr_fd(plateau.x, fd);
				ft_putstr_fd("<-\n", fd);
			}
			if (1) //вывод карты
			{
				ft_putstr_fd("---+------------+----------+---\n", fd);
				ft_put_map_chr_fd(plateau.board, plateau.n, plateau.x, fd);
				ft_putstr_fd("---+------------+----------+---\n", fd);
			}

			if (1) // проверка на координаты токена
			{
				ft_putstr_fd("->piece N - ", fd);
				ft_putnbr_fd(piece.n, fd);
				ft_putstr_fd(" [", fd);
				ft_putnbr_fd(piece.min.n, fd);
				ft_putstr_fd("]<-\n->piece X - ", fd);
				ft_putnbr_fd(piece.x, fd);
				ft_putstr_fd(" [", fd);
				ft_putnbr_fd(piece.min.x, fd);
				ft_putstr_fd("]<-\n", fd);
			}
			if (1) //вывод токена
			{
				ft_putstr_fd("---+------------+----------+---\n", fd);
				ft_put_map_chr_fd(piece.token, piece.n, piece.x, fd);
				ft_putstr_fd("---+------------+----------+---\n", fd);
			}
		}
		if (piece.token)
			ft_map_chr_del(piece.token, piece.n); //фришим токен
		print_answer(&point);

		if (point.n < 0 && point.x < 0)
		{
			ft_map_int_del(plateau.heatmap, plateau.n);
			ft_map_chr_del(plateau.board, plateau.n);
			break ;
		}
	}
	close(fd);
	return 0;
}
