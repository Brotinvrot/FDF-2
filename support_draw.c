/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:57:33 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/24 14:34:31 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	who_max(int first, int second)
{
	if (first >= second)
		return (first);
	return (second);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*pixel;

	if (x >= 0 && x < data -> window_width && y >= 0 && \
			y < data -> window_height)
	{
		pixel = data -> addr + (y * data -> line_length + x \
			* (data -> bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

int	che_col(t_Pixel pixel1, t_Pixel pixel2)
{
	if (pixel1.color == 0x449e48)
		if (pixel1.z != 0 || pixel2.z != 0)
			return (0xFF0000);
	return (pixel1.color);
}

int	ft_abs(int first, int second)
{
	int	result;

	result = first - second;
	if (result < 0)
		return (result * -1);
	return (result);
}
