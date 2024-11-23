/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 13:28:01 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/23 15:30:17 by drabadan         ###   ########.fr       */
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

void	key_press_next(int keycode, t_fdf *data)
{
	if (keycode == 122)
	{
		if (data ->scale_z <= 10)
			data -> scale_z += 1;	
	}
	else if (keycode == 120)
	{
		if (data -> scale_z >= -10)
			data -> scale_z -= 1;
	}
}

int	key_press(int keycode, t_fdf *data)
{
	printf("%d\n", keycode);
	printf("p_size = %d\n", data -> pixel_size);
	printf("scale_z = %d\n", data -> scale_z);
	if (keycode == 65307)
		close_window(data);
	else if (keycode == 65362)
		data -> offset_y += 10;
	else if (keycode == 65364)
		data -> offset_y -= 10;
	else if (keycode == 65363)
		data -> offset_x += 10;
	else if (keycode == 65361)
		data -> offset_x -= 10;
	else if (keycode == 65453 && data -> pixel_size > 2)
		data -> pixel_size -= 1;
	else if (keycode == 65451 && data -> pixel_size < 40)
		data -> pixel_size += 1;
	else
		key_press_next(keycode, data);
	mlx_destroy_image(data->mlx_ptr, data->img_ptr);
	data->img_ptr = mlx_new_image(data->mlx_ptr, data->window_width, \
		data->window_height);
	data->addr = mlx_get_data_addr(data->img_ptr, &data->bits_per_pixel, \
		&data->line_length, &data->endian);
	draw(data);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	return (0);
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

void	second_step(t_fdf *data)
{
	data -> pixel_size = 10;
	data -> window_width = 1920;
	data -> window_height = 1080;
	data -> offset_x = (data -> window_width - ((data -> map_width - 1) \
		* data -> pixel_size)) / 2;
	data -> offset_y = (data -> window_height - ((data -> map_height - 1) \
		* data -> pixel_size)) / 2;
	data -> scale_z = 1;
	data -> mlx_ptr = mlx_init();
	data -> win_ptr = mlx_new_window(data -> mlx_ptr, data -> window_width, \
		data -> window_height, "FDF");
	data -> img_ptr = mlx_new_image(data -> mlx_ptr, data -> window_width, \
		data -> window_height);
	data -> addr = mlx_get_data_addr(data -> img_ptr, &data -> bits_per_pixel, \
		&data -> line_length, &data -> endian);
	draw(data);
	mlx_put_image_to_window(data -> mlx_ptr, data -> win_ptr, \
		data -> img_ptr, 0, 0);
	mlx_hook(data -> win_ptr, 17, 0, close_window, data);
	mlx_hook(data -> win_ptr, 2, 1L << 0, key_press, data);
	mlx_loop(data -> mlx_ptr);
}
