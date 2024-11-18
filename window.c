/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:28:01 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/18 13:49:08 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	close_window(t_fdf *data)
{
	int	i;

	i = 0;
	while (i < data -> map_height)
	{
		free(data -> matrix[i]);
		i++;
	}
	free(data -> matrix);
	mlx_destroy_image(data -> mlx_ptr, data -> img_ptr);
	mlx_destroy_window(data -> mlx_ptr, data -> win_ptr);
	mlx_destroy_display(data -> mlx_ptr);
	free(data -> mlx_ptr);
	exit(0);
}

int	key_press(int keycode, t_fdf *data)
{
	if (keycode == 65307)
		close_window(data);
	printf("%d\n", keycode);
	return (0);
}

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*pixel;
	
	if (x >= 0 && x < data -> window_width && y >= 0 && y < data -> window_height)
	{
		pixel = data -> addr + (y * data->line_length + x * (data -> bits_per_pixel / 8));
		*(unsigned int *)pixel = color;
	}
}

void	draw(t_fdf *data)
{
	int	x;
	int	y;
	int	i;

	y = 0;
	while (y < data -> map_height)
	{
		x = 0;
		while (x < data -> map_width)
		{
			i = 0;
			my_mlx_pixel_put(data, data -> offset_x + (x * data -> pixel_size), data -> offset_y + (y * data -> pixel_size), 0x00FF00);
			while (i < data -> pixel_size)
			{
				if (x != data -> map_width - 1)
					my_mlx_pixel_put(data, data -> offset_x + i + (x * data -> pixel_size), data -> offset_y + (y * data -> pixel_size), 0x00FF00);
				if (y != data -> map_height - 1)
					my_mlx_pixel_put(data, data -> offset_x + (x * data -> pixel_size), data -> offset_y + i + (y * data -> pixel_size), 0x00FF00);
				i++;
			}
			x++;
		}
		y++; 
	}
}

void	second_step(t_fdf *data)
{
	data -> pixel_size = 10;
	data -> window_width = (data -> map_width - 1) * data -> pixel_size + 100;
	data -> window_height = (data -> map_height - 1) * data -> pixel_size + 100;
 	data -> offset_x = (data -> window_width - ((data -> map_width - 1) * data -> pixel_size)) / 2;
	data -> offset_y = (data -> window_height - ((data -> map_height - 1) * data -> pixel_size)) / 2;
	data -> mlx_ptr = mlx_init();
	data -> win_ptr = mlx_new_window(data -> mlx_ptr, data -> window_width, data -> window_height, "FDF");
	data -> img_ptr = mlx_new_image(data -> mlx_ptr, data -> window_width, data -> window_height);
	data -> addr = mlx_get_data_addr(data -> img_ptr, &data -> bits_per_pixel, &data -> line_length, &data -> endian);

	draw(data);
	mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr, data -> img_ptr, 0, 0);

	mlx_hook(data -> win_ptr, 17, 0, close_window, data);
	mlx_hook(data -> win_ptr, 2, 1L<<0, key_press, data);

	mlx_loop(data -> mlx_ptr);
}
