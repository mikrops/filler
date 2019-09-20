/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:28:45 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/20 14:47:13 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_FILLER_H
#define FILLER_FILLER_H

# include "libft/libft.h"
# include "get_next_line/get_next_line.h"

/*
**	The board
*/

typedef struct	s_plateau
{
	char 		**board;
	int			**heatmap;
	int 		n; //lines //row
	int 		x; //columns
}				t_plateau;

/*
**	The tokens
*/

typedef struct	s_piece
{
	char 		**token;
	int 		n; //lines //row
	int 		x; //columns
	int			length;
}				t_piece;

/*
**	The player
*/

typedef struct	s_player
{
	int 		number;
	int 		n;
	int 		x;
}				t_player;

/*
**	The answer
*/

typedef struct	s_point
{
	int 		n;
	int 		x;
}				t_point;



void			heat_map(t_plateau *plateau, t_piece *piece, t_player *player);
void			insert_piece(t_plateau *plateau, t_piece *piece, t_point *point);

#endif
