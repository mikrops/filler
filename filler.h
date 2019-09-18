/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:28:45 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/14 18:54:48 by mmonahan         ###   ########.fr       */
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
	int 		x; //columns
	int 		n; //lines
}				t_plateau;

/*
**	The tokens
*/

typedef struct	s_piece
{
	char 		**token;
	int 		x; //columns
	int 		n; //lines
}				t_piece;

/*
**	The player
*/

typedef struct	s_player
{
	int 		number;
	int 		x;
	int 		n;
}				t_player;

void			heat_map(t_plateau *plateau, t_piece piece, t_player player);

#endif
