/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 11:18:47 by lsouquie          #+#    #+#             */
/*   Updated: 2022/12/16 16:30:59 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*clean_it(char *stash, int readed)
{
	char 	*temp;
	int		i;
	int 	j;

	i = 0;
	j = 0;
	if (readed == 0)
	{
		free (stash);
		return (NULL);
	}
	while (stash[i])
	{
		if (stash[i] == '\n')
			break ;
		i++;
	}
	i += 1;
	temp = malloc (sizeof(char *) * (ft_strlen(stash) - i) + 1);
	while (stash[i])
		temp[j++] = stash[i++];
	temp[i] = '\0';
	free (stash);
	return (temp);
}

char	*add_it(char *stash, char *line)
{
	int	i;
	int len;

	len = 0;
	i = 0;
	while (stash[len] != '\0' || stash[len] != '\n')
		len++;
	if (stash[len] == '\n')
		len++;
	line = malloc(sizeof(char *) * (len + 1));
	if (!line)
		return (NULL);
	while (stash[i])
	{
		line[i] = stash[i];
		if (stash[i] == '\n')
		{
	//		line[i] = '\n';
			break ;
		}
		i++;
	}
	line[++i] = '\0';
	return (line);
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

/*char	*stash_it(char *stash, int fd)
{

	return (stash);
}*/

char	*get_next_line(int fd)
{
	static char	*stash;
	char		*line;
	char	*buf;
	int		readed;

	
	readed = 1;
	line = 0;
	buf = malloc(sizeof(char) * BUFFER_SIZE + 1);
	if (!buf)
		return (NULL);
	while (!found_newline(buf) && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		buf[readed] = '\0';
		stash = ft_strjoin(stash, buf);
	}
	free(buf);
	// printf("Ici taille : %ld\n", ft_strlen(stash));

	line = add_it(stash, line);
	stash = clean_it(stash, readed);
	return (line);
}
