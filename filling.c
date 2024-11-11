/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filling.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 18:18:35 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/11 16:47:08 by drabadan         ###   ########.fr       */
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
	char	**array;

	array = ft_split(str, ',');
	*color = ft_atoi_hex(array[1]);
	free(array[0]);
	free(array[1]);
	free(array);
}

void	cor_filling_2(char **array, t_Pixel **matrix, int y)
{
	int	i;

	i = 0;
	while (array[i] != NULL)
	{
		if (comma(array[i]) == 0)
			add_color(array[i], &matrix[y][i].color);
		matrix[y][i].y = y;
		matrix[y][i].x = i;
		matrix[y][i].z = ft_atoi(array[i]);
		//printf("x = %d y = %d z = %d color = %d\n", matrix[y][i].x, matrix[y][i].y, matrix[y][i].z, matrix[y][i].color);
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
	while (line != NULL)
	{
		line = get_next_line(fd);
		if (line == NULL)
		{
			free(line);
			break ;
		}
		array = ft_split(line, ' ');
		free(line);
		cor_filling_2(array, data -> matrix, y);
		free(array);
		y++;
	}
}
