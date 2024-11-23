/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   support_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 14:57:33 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/23 14:09:36 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	che_col(t_Pixel pixel1, t_Pixel pixel2)
{
	if (pixel1.color == 0x449e48 && pixel1.z != 0 && pixel2.z != 0)
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
