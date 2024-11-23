/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:52:07 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/23 16:35:17 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	who_max(int first, int second)
{
	if (first >= second)
		return (first);
	return (second);
}

void	trans_point(t_Pixel *point, t_fdf *data)
{
	point -> x = point -> x * data -> pixel_size + data -> offset_x;
	point -> y = point -> y * data -> pixel_size + data -> offset_y;
	point -> x += data -> offset_x;
	point -> y += data -> offset_y;
}

void	isometric(t_Pixel *pixel, t_fdf *data)
{
	float	prev_x;
	float	prev_y;

	prev_x = pixel -> x;
	prev_y = pixel -> y;
	pixel -> x = (prev_x - prev_y) * cos(0.523599);
	pixel -> y = (prev_x + prev_y) * sin(0.3) - pixel -> z * data -> scale_z;
}

void	bresenham(t_Pixel p1, t_Pixel p2, t_fdf *data)
{
	int		max;
	float	x_step;
	float	y_step;

	trans_point(&p1, data);
	trans_point(&p2, data);
	isometric(&p1, data);
	isometric(&p2, data);
	max = who_max(ft_abs(p2.x, p1.x), ft_abs(p2.y, p1.y));
	x_step = (p2.x - p1.x) / (float)max;
	y_step = (p2.y - p1.y) / (float)max;
	while (fabs(p1.x - p2.x) > 0.1 || fabs(p1.y - p2.y) > 0.1)
	{
		my_mlx_pixel_put(data, p1.x, p1.y, che_col(p1, p2));
		p1.x += x_step;
		p1.y += y_step;
	}
	my_mlx_pixel_put(data, p2.x, p2.y, che_col(p2, p2));
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data -> map_height)
	{
		x = 0;
		while (x < data -> map_width)
		{
			if (x < data -> map_width - 1)
				bresenham(data -> matrix[y][x], data -> matrix[y][x + 1], data);
			if (y < data -> map_height - 1)
				bresenham(data -> matrix[y][x], data -> matrix[y + 1][x], data);
			x++;
		}
		y++;
	}
}
