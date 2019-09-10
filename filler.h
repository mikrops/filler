/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/02 16:28:45 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/09 20:23:49 by mmonahan         ###   ########.fr       */
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
	char 		**plateau;
	int 		x;
	int 		n;
}				t_plateau;

/*
**	The tokens
*/

typedef struct	s_piece
{
	char 		**piece;
	int 		x;
	int 		n;
}				t_piece;

/*
**	The player
*/

typedef struct	s_player
{
	char 		first;
	char 		last;
}				t_player;



#endif
