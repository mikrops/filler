/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_answer.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/20 16:39:30 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/23 20:14:53 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void print_answer(t_point *point)
{
	ft_putnbr_fd(point->n, 1);
	ft_putchar_fd(' ', 1);
	ft_putnbr_fd(point->x, 1);
	ft_putchar_fd('\n', 1);
}
