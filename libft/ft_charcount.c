/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_charcount.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmonahan <mmonahan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:53:25 by mmonahan          #+#    #+#             */
/*   Updated: 2019/09/23 20:14:53 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
**	Возвращает колличество символов от начала строки S до символа C
**	не включая его. Если символа в строке нет, возвращает длину строки.
**	Если строка или символ не указаны, возвращает 0.
*/

size_t	ft_charcount(char const *s, char c)
{
	size_t count;

	count = 0;
	if (!s || !c)
		return (count);
	while (*s != c && *s != '\0')
	{
		count++;
		s++;
	}
	return (count);
}
