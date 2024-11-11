/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:20:42 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/11 08:47:55 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "./Libft/src/libft.h"
# include <math.h>
# include <mlx.h>

# include <stdio.h>// Удалить ОБЯЗАТЕЛЬНО

typedef struct s_pixel_data
{
	int	x;
	int	y;
	int	z;
	int	color;
}	t_Pixel;

typedef struct s_fdf
{
	int		map_width;
	int		map_height;
	t_Pixel	**matrix;

}	t_fdf;

void	first_step(char *str, t_fdf *data);
void	cor_filling(char *str, t_fdf *data);

#endif
