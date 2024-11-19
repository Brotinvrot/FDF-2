/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 13:52:07 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/18 20:54:51 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	ft_abs(int first, int second)
{
	int	result;

	result = first - second;
	if (result < 0)
		return (result * -1);
	return (result);
}

int	who_max(int first, int second)
{
	if (first >= second)
		return (first);
	return (second);
}

void	bresenham(t_Pixel p1, t_Pixel p2, t_fdf *data)
{
	float	x_step;
	float	y_step;
	int		max;

	x_step = ft_abs(p2.x, p1.x);
	y_step = ft_abs(p2.y, p1.y);
	max = who_max(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(p1.x - p2.x) || (int)(p1.y - p2.y ))
	{
		my_mlx_pixel_put(data, p1.x, p2.y, p1.color);
		p1.x += x_step;
		p1.y += y_step;
	}
}
