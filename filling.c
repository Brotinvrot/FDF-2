/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:18:35 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/12 11:08:39 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	comma(char *str)
{
	while (*str)
	{
		if (*str == ',')
			return (0);
		str++;
	}
	return (1);
}

void	add_color(char *str, int *color)
{
	int		i;
	char	**array;

	array = ft_split(str, ',');
	*color = ft_atoi_hex(array[1]);
	i = 0;
	while(array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	cor_filling_2(char **array, t_fdf *data, int y)
{
	int	i;

	i = 0;
	while (i < data -> map_width)
	{
		if (comma(array[i]) == 0)
			add_color(array[i], &data -> matrix[y][i].color);
		data -> matrix[y][i].y = y;
		data -> matrix[y][i].x = i;
		data -> matrix[y][i].z = ft_atoi(array[i]);
		free(array[i]);
		i++;
	}
	while (array[i] != NULL)
	{
		free(array[i]);
		i++;
	}
}

void	cor_filling(char *str, t_fdf *data)
{
	int		fd;
	int		y;
	char	*line;
	char	**array;

	fd = open(str, O_RDONLY);
	line = "";
	y = 0;
	while (line != NULL && y < data -> map_height)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		array = ft_split(line, ' ');
		free(line);
		cor_filling_2(array, data, y);
		free(array);
		y++;
	}
	close(fd);
}
