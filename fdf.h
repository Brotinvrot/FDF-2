/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:20:42 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/24 15:27:46 by drabadan         ###   ########.fr       */
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
	float	x;
	float	y;
	int		z;
	int		color;
}	t_Pixel;

typedef struct s_fdf
{
	int		map_width;
	int		map_height;
	int		offset_x;
	int		offset_y;
	int		pixel_size;
	t_Pixel	**matrix;
	int		window_height;
	int		window_width;
	int		scale_z;
	int		projection;
	float	rotation_z;
	void	*win_ptr;
	void	*mlx_ptr;
	void	*img_ptr;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;

}	t_fdf;

void	first_step(char *str, t_fdf *data);
void	cor_filling(char *str, t_fdf *data);
void	second_step(t_fdf *data);
void	rotate_z(t_Pixel *point, float angle);
void	apply_rotation(t_Pixel *point, t_fdf *data);
int		who_max(int first, int second);
int		ft_abs(int first, int second);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
void	draw(t_fdf *data);
int		ft_abs(int first, int second);
int		che_col(t_Pixel pixel1, t_Pixel pixel2);

#endif

/*
int interpolate_color(int start_color, int end_color, float percentage)
{
	int red = ((start_color >> 16) & 0xFF) + percentage * (((end_color >> 16) & 0xFF) - ((start_color >> 16) & 0xFF));
	int green = ((start_color >> 8) & 0xFF) + percentage * (((end_color >> 8) & 0xFF) - ((start_color >> 8) & 0xFF));
	int blue = (start_color & 0xFF) + percentage * ((end_color & 0xFF) - (start_color & 0xFF));
	return ((red << 16) | (green << 8) | blue);
}
*/