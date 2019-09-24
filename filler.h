/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:28:45 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/24 20:52:54 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"


/*
**	The answer
**		n: rows
**		x: columns
*/

typedef struct	s_point
{
	int 		n;
	int 		x;
}				t_point;

/*
**	The board
*/

typedef struct	s_plateau
{
	char 		**board;
	int			**heatmap;
	int 		n;
	int 		x;
}				t_plateau;

/*
**	The tokens
*/

typedef struct	s_piece
{
	char 		**token;
	int 		n;
	int 		x;
	t_point		min;
}				t_piece;

/*
**	The player
*/

typedef struct	s_player
{
	int 		number;
	int 		o;
	int 		x;
}				t_player;




void			heat_map(t_plateau *plateau, t_player *player);
void			insert_piece(t_plateau *plateau, t_piece *piece, t_point *point);
void			get_player(t_player *player);
void			get_piece(t_piece *piece);
void			print_answer(t_point *point);
void			ft_map_int_del(int **map, size_t row);
void			ft_map_chr_del(char **map, size_t row);
#endif
