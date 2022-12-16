/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:57:34 by lsouquie          #+#    #+#             */
/*   Updated: 2022/12/16 16:17:26 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int	fd;
	char *line;
	int		i;

	fd = open("./text.txt", O_RDONLY);
	i = 1;
	while (i <= 15)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		printf("%s", line);
		free(line);
		i++;
	}
	return (0);
}