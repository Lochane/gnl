/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lsouquie <lsouquie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 10:57:34 by lsouquie          #+#    #+#             */
/*   Updated: 2022/12/13 17:40:25 by lsouquie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main()
{
	int	fd;
	char *line;

	fd = open("./text.txt", O_RDONLY);
	// while (1)
		line = get_next_line(fd);
	//	if (!line)
		//	break ;
		printf("%s", line);
		free(line);
	return (0);
}