/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:28:45 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/25 13:10:06 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"


/*
**	The point
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

/*
**	Function for filler
*/

void			get_player(t_player *player);
void			get_plateau(t_plateau *plateau);
void			get_piece(t_piece *piece);
void			get_size(int *n, int *x);

/*
**	Extra function for filler
*/

void			fill_map(char **matrix, int row, int col);
void			heat_map(t_plateau *plateau, t_player *player);
void			put_piece(t_plateau *plateau, t_piece *piece, t_point *point);
#endif
