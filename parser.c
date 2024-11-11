/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 16:45:57 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/11 08:46:58 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error_messeg(void)
{
	write(2, "Error: could not open file\n", 27);
	exit (1);
}

int	get_map_height(int fd)
{
	int		size;
	char	*line;

	size = 0;
	line = "";
	while (line)
	{
		line = get_next_line(fd);
		free(line);
		size++;
	}
	return (size);
}

int	get_map_width(int fd)
{
	int		size;
	int		i;
	char	*line;
	char	**array;

	size = 0;
	i = 0;
	line = get_next_line(fd);
	array = ft_split(line, ' ');
	while (array[i])
	{
		if (array[i])
			if ((array[i][0] >= '0' && array[i][0] <= '9') || \
				array[i][0] == '-')
				size++;
		free(array[i]);
		i++;
	}
	free(line);
	free(array);
	return (size);
}

void	alloc_mem(t_fdf *data)
{
	int	i;

	data -> matrix = malloc(data -> map_height * sizeof(t_Pixel *));
	i = 0;
	while (i < data -> map_height)
	{
		data -> matrix[i] = malloc(data -> map_width * sizeof(t_Pixel));
		i++;
	}
}

void	first_step(char *str, t_fdf *data)
{
	int		fd;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		error_messeg();
	data -> map_width = get_map_width(fd);
	data -> map_height = get_map_height(fd);
	close(fd);
	alloc_mem(data);
	cor_filling(str, data);
	//printf("width = %d\nheight = %d\n", data -> map_width, data -> map_height);
}
