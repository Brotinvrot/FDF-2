/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:52:07 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/24 15:25:47 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	bresenham_next(int max, t_Pixel *p1, t_Pixel *p2, t_fdf *data)
{
	int		i;
	float	x_step;
	float	y_step;

	x_step = (p2 -> x - p1 -> x) / (float)max;
	y_step = (p2 -> y - p1 -> y) / (float)max;
	i = 0;
	while (i <= max)
	{
		my_mlx_pixel_put(data, p1 -> x, p1 -> y, che_col(*p1, *p2));
		p1 -> x += x_step;
		p1 -> y += y_step;
		i++;
	}
}

void	trans_point(t_Pixel *point, t_fdf *data)
{
	apply_rotation(point, data);
	point -> x = point -> x * data -> pixel_size + data -> offset_x;
	point -> y = point -> y * data -> pixel_size + data -> offset_y;
	point -> z *= data -> scale_z;
	point -> x += data -> offset_x;
	point -> y += data -> offset_y;
}

void	isometric(t_Pixel *pixel)
{
	float	prev_x;
	float	prev_y;

	prev_x = pixel -> x;
	prev_y = pixel -> y;
	pixel -> x = (prev_x - prev_y) * cos(0.523599);
	pixel -> y = (prev_x + prev_y) * sin(0.3) - pixel -> z;
}

void	bresenham(t_Pixel p1, t_Pixel p2, t_fdf *data)
{
	int		max;

	trans_point(&p1, data);
	trans_point(&p2, data);
	if (data -> projection == 0)
	{
		isometric(&p1);
		isometric(&p2);
	}
	max = who_max(ft_abs(p2.x, p1.x), ft_abs(p2.y, p1.y));
	if (max == 0)
		return ;
	bresenham_next(max, &p1, &p2, data);
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
