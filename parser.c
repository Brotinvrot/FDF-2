/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:45:57 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/07 11:12:18 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void	maping_line(char *line)
{
	if (line == NULL)
		return ;
	printf("line = %s", line);
	free(line);
}

void	first_step(char *str)
{
	int	fd;
	char	*line;

	fd = open(str, O_RDONLY);
	line = "";
	if (fd == -1)
	{
		write(2, "Error: could not open file\n", 27);
		exit (1);
	}
	while (line != NULL)
	{
		line = get_next_line(fd);
		printf("line = %s", line);
		free(line);
	}
}
