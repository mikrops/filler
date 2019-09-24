/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dheidenr <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 01:40:51 by dheidenr          #+#    #+#             */
/*   Updated: 2019/09/24 20:03:36 by mmonahan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_list	*list_of_fd(t_list **list, int fd)
{
	t_list		*newlist;

	newlist = *list;
	while (newlist)
	{
		if ((int)newlist->content_size == fd)
			return (newlist);
		newlist = newlist->next;
	}
	newlist = ft_lstnew("\0", fd);
	ft_lstadd(list, newlist);
	newlist = *list;
	return (newlist);
}

static	char	*recontent(t_list **list)
{
	size_t		len;
	char		*tmp;
	char		*line;
	char		*content;

	len = 0;
	line = NULL;
	tmp = LSTLC;
	while (*tmp != '\n' && *tmp != '\0')
	{
		tmp++;
		len++;
	}
	content = line;
	line = ft_strsub((const char *)LSTLC, 0, len);
	free(content);
	content = NULL;
	content = LSTLC;
	if (*tmp == '\n')
		LSTLC = ft_strdup(LSTLC + len + 1);
	else if (*tmp == '\0')
		LSTLC = ft_strdup(LSTLC + len);
	free(content);
	content = NULL;
	return (line);
}

static	int		ft_tmplc(char **content, t_list **list, char **buff)
{
	*content = LSTLC;
	LSTLC = ft_strjoin((char *)LSTLC, *buff);
	ft_memdel((void *)content);
	return ((!LSTLC) ? 0 : 1);
}

static	int		cbuff(char **buff)
{
	ft_memdel((void *)buff);
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static	t_list	*list;
	char			*content;
	char			*buff;
	int				nbread;
	t_list			*tmplist;

	if ((fd < 0 || read(fd, (buff = NULL), 0) < 0 || line == NULL))
		return (-1);
	else if ((!(tmplist = list_of_fd(&list, fd)) &&
		(!(TMPLC = "\0"))) ||
		(!(buff = (char *)ft_memalloc((BUFF_SIZE + 1) * sizeof(*buff)))))
		return (0);
	while ((!ft_strchr(TMPLC, '\n')) &&
		((nbread = read(fd, (void *)buff, BUFF_SIZE)) != 0))
	{
		if (!(buff[BUFF_SIZE] = '\0') && nbread < 0)
			return (-1);
		if (!(ft_tmplc(&content, &tmplist, &buff)))
			if ((TMPLC = "\0") && ft_strchr(buff, '\n'))
				break ;
		(void)ft_memset((void *)buff, 0, BUFF_SIZE + 1);
	}
	if (((char *)TMPLC)[0] == '\0' && nbread < BUFF_SIZE && buff[0] == '\0')
		return (0);
	return (((*line = recontent(&tmplist)) && cbuff(&buff)) ? 1 : 0);
}
