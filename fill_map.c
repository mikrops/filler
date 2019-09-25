/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/25 12:41:21 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/25 12:41:21 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

/*
**	Заполнение матрицы[row][col] из потока 0
*/

void	fill_map(char **map, int row, int col)
{
	char	*str;
	int		i;
	int		j;
	int		shift;

	i = 0;
	j = 0;
	shift = 0;
	while (j < row)
	{
		get_next_line(0, &str);
		while (ft_isdigit(str[shift]) || ft_isspace(str[shift]))
			shift++;
		while (i < col)
		{
			map[j][i] = str[i + shift];
			i++;
		}
		i = 0;
		j++;
		shift = 0;
		free(str);
	}
}
