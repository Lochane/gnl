/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lochane <lochane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:18:47 by lsouquie          #+#    #+#             */
/*   Updated: 2022/12/15 18:21:36 by lochane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*add_it(char *stash, char *line)
{
	int i;

	i = 0;
	while(stash[i])
	{
		line[i] = stash[i];
		i++;
	}
	line[i] = '\0';
	return(line);
}

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
	line = malloc(sizeof(char *) * ft_strlen(stash));
	if (!line)
		return (NULL);
	// 2. extract from stash to line
	line = add_it(stash, line);
	// 3. clean up stash
	return (line);
}