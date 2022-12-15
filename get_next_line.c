/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:18:47 by lsouquie          #+#    #+#             */
/*   Updated: 2022/12/15 13:46:22 by lsouquie         ###   ########.fr       */
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

char	*stash_it(char *stash, int fd)
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
		stash = ft_strjoin(stash, buf);
	}
	printf("%s", stash);
	return (stash);
}

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;

	line = NULL;
	stash = NULL;
	
	// 1. read from fd and add to linked list
	stash = stash_it(stash, fd);
	// 	printf("%s", stash->content);
	// 2. extract from stash to line
	// add_it(line, stash);
	// 3. clean up stash
	return (line);
}