/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:20:42 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/18 13:52:36 by drabadan         ###   ########.fr       */
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
	int		map_width;			// Ширина карты
	int		map_height;			// Высота карты
	int		offset_x;			// Смещение по Х, что бы отрисовывать по центру
	int		offset_y;			// Смещение по У, что бы отрисовывать по центру
	int		pixel_size;			// Колличество пикселей между точками
	t_Pixel	**matrix;			// Структура координат с их значениями.

	int		window_height;
	int		window_width;
	void	*win_ptr;			// Указатель на инициализацию окна
	void	*mlx_ptr;			// Указатель на инициализацию библиотеки MLX
	void	*img_ptr;			// Указатель на изображение
	char	*addr;				// Адресс пикселей изображения
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}	t_fdf;

void	first_step(char *str, t_fdf *data);
void	cor_filling(char *str, t_fdf *data);
void	second_step(t_fdf *data);
int		ft_abs(int first, int second);

#endif
