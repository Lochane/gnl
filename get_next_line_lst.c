/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_lst.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 16:10:00 by lsouquie          #+#    #+#             */
/*   Updated: 2022/12/15 11:19:39 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	found_newline(char *buf)
{
	int	i;

	i = 0;
	while (buf[i])
	{
		if (buf[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

t_list	*add_to_stash(t_list **stash, char *buf)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new->content = buf;
	new->next = NULL;
	if ((*stash) == NULL)
	{	
		(*stash) = new;
		return ((*stash));
	}
	while ((*stash)->next != NULL)
		(*stash) = (*stash)->next;
	return ((*stash));
}

t_list	*stash_it(t_list **stash, int fd)
{
	char	*buf;
	int		readed;

	readed = 1;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!found_newline(buf) && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		buf[readed] = '\0';
		(*stash) = add_to_stash(&(*stash), buf);
	}
	return ((*stash));
}

void	add_it(char **line, t_list **stash)
{
	int	i;

	i = 0;
	while ((*stash)->content[i] != '\0' && (*stash)->content[i] != '\n')
	{
		(*line)[i] = (*stash)->content[i];
		i++;
	}
}

char	*get_next_line_lst(int fd)
{
	static t_list	*stash;
	char			*line;

	line = NULL;
	stash = NULL;
	
	// 1. read from fd and add to linked list
	stash = stash_it(&stash, fd);
	// while (stash->content != NULL)
	// 	printf("%s", stash->content);
	// 2. extract from stash to line
	add_it(&line, &stash);
	// 3. clean up stash
	return (line);
}