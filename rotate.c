/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:09:41 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/24 15:27:23 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	rotate_z(t_Pixel *point, float angle)
{
	float	prev_x;
	float	prev_y;

	prev_x = point -> x;
	prev_y = point -> y;
	point->x = prev_x * cos(angle) - prev_y * sin(angle);
	point->y = prev_x * sin(angle) + prev_y * cos(angle);
}

void	apply_rotation(t_Pixel *point, t_fdf *data)
{
	if (data -> rotation_z != 0)
		rotate_z(point, data -> rotation_z);
}
