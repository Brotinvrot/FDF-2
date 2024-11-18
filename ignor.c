
	int	screen_width = 1920;
	int	screen_height = 1080;

	int	max_pixel_size_width = screen_width / data -> map_width;
	int	max_pixel_size_height = screen_height / data -> map_height;

	int	pixel_size;

	if (max_pixel_size_width < max_pixel_size_height)
		pixel_size = max_pixel_size_width;
	else
		pixel_size = max_pixel_size_height;

	int	window_width = data -> map_width * pixel_size;
	int	window_height = data -> map_height * pixel_size;

	void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	if (x >= 0 && x < 1920 && y >= 0 && y < 1080) // Проверка на границы экрана
	{
		dst = data -> adres + (y * data->line_length + x * (data->bits_per_pixel / 8));
		*(unsigned int*)dst = color;
	}
}

void	draw_map(t_fdf *data)
{
	for (int y = 0; y < data -> map_height; y++)
	{
		for (int x = 0; x < data -> map_width; x++)
		{
			// Здесь логика отрисовки, например:
			my_mlx_pixel_put(data, x * data -> pixel_size, y * data -> pixel_size, 0xFFFFFF); // Белый цвет
		}
	}
}

	draw_map(data);
	data -> img_ptr = mlx_new_image(data -> mlx_ptr, 1920, 1080);
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr, data->img_ptr, 0, 0);
	data -> adres = mlx_get_data_addr(data -> img_ptr, &data -> bits_per_pixel, &data -> line_length, &data -> endian);