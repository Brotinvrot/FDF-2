/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:55:04 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/10 13:07:50 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
int	key_hook(int keycode)
{
	if (keycode == 65307)
		exit(0);
	return (0);
}

int	ft_abs(int first, int second)
{
	int result;

	result = first - second;
	if (result < 0)
		return (result * -1);
	return (result);
}

void	draw_line(void *mlx, void *window, t_fdf p1, t_fdf p2)
{
	
	int	distans_x;// это разница между точкой 1 и 2 по оси Х
	int	distans_y;// это разницв между точкой 1 и 2 по оси У
	int	x;
	int	y;
	int	sx;
	int	sy;
	int	err;
	int	tmp_err;

	distans_x = ft_abs(p2.map_size_x, p1.map_size_x);// вычисляем с помощью функции что бы убрать (-)
	distans_y = ft_abs(p2.map_size_y, p1.map_size_y);
	x = p1.map_size_x;// получаем адреса по (х) и (у) от первой точки что бы двигаться вперёд
	y = p1.map_size_y;// и изменяить ткущее значение

	// int	sx = (p1.x < p2.x) ? 1 : -1; очень удобный и простой тернарный опратор
	// int	sy = (p1.y < p2.y) ? 1 : -1; однако по нормам не пройдёт

	if (p1.map_size_x < p2.map_size_x)
		sx = 1;
	else
		sx = -1;
	if (p1.map_size_y < p2.map_size_y)
		sy = 1;
	else
		sy = -1;
	err = distans_x - distans_y;
	while (x != p2.map_size_x || y != p2.map_size_y)
	{
		mlx_pixel_put(mlx, window, x, y, 0xFFFFFF);
		tmp_err = 2 * err;
		if (tmp_err > -distans_y)
		{
			err -= distans_y;
			x += sx;
		}
		if (tmp_err < distans_x)
		{
			err += distans_x;
			y += sy;
		}
	}
	mlx_pixel_put(mlx, window, p2.map_size_x, p2.map_size_y, 0xFFFFFF);
}
*/

int	main(int argc, char **argv)
{
	int		i;
	t_fdf	data;

	if (argc != 2)
	{
		write(2, "Do this: ./fdf <filename>\n", 26);
		return (1);
	}
	first_step(argv[1], &data);
	i = 0;
	while (i < data.map_height)
	{
		free(data.matrix[i]);
		i++;
	}
	free(data.matrix);
	return (0);
}









/* отрисовка сетки, в общем сетка нужна что бы затем рисовать по ней проекцию
	так же размер сетки должен варьироватся в зависимости от карты.
	Парсишь карту высчитываешь длинну ширину и изходя из полученных размеров
	задаешь размер сетки.
	Итог:

Программа должна:
    1 Прочитать карту и определить её размеры.
    2 Вычислить оптимальный размер клетки, чтобы карта поместилась в окно.
    3 Масштабировать высоту рельефа для адекватного отображения высот.
    4 Отрисовывать карту с динамически вычисленными значениями, чтобы отображение
	было корректным для карт любого размера.
*/
	// void	*mlx;
	// void	*window;
	// t_data p1;
	// t_data p2;

	// mlx = mlx_init();
	// if (mlx == NULL)
	// 	return (1);
	// window = mlx_new_window(mlx, 800, 600, "FDF_drabadan");
	// if (window == NULL)
	// 	return (1);
	// mlx_key_hook (window, key_hook, NULL);
	// p1.map_size_x = 100;
	// p1.map_size_y = 100;
	// p2.map_size_x = 500;
	// p2.map_size_y = 300;
	// draw_line(mlx, window, p1, p2);
	// p1.map_size_x = 200;
	// p1.map_size_y = 400;
	// p2.map_size_x = 600;
	// p2.map_size_y = 100;
	// draw_line(mlx, window, p1, p2);
	// mlx_loop (mlx);

// #include <mlx.h>
// #include <stdlib.h>

// typedef struct s_point
// {
// 	int x;
// 	int y;
// }	t_point;

// // Функция для рисования линий
// void	draw_line(void *mlx, void *window, t_point p1, t_point p2)
// {
// 	int dx = abs(p2.x - p1.x);
// 	int sx = p1.x < p2.x ? 1 : -1;
// 	int dy = -abs(p2.y - p1.y);
// 	int sy = p1.y < p2.y ? 1 : -1;
// 	int err = dx + dy;
// 	int e2;

// 	while (1)
// 	{
// 		mlx_pixel_put(mlx, window, p1.x, p1.y, 0xFFFFFF);
// 		if (p1.x == p2.x && p1.y == p2.y)
// 			break;
// 		e2 = 2 * err;
// 		if (e2 >= dy) { err += dy; p1.x += sx; }
// 		if (e2 <= dx) { err += dx; p1.y += sy; }
// 	}
// }

// void	draw_letter_X(void *mlx, void *window)
// {
// 	t_point p1, p2;

// 	// Линия \ для Х
// 	p1.x = 100; p1.y = 100;
// 	p2.x = 150; p2.y = 150;
// 	draw_line(mlx, window, p1, p2);

// 	// Линия / для Х
// 	p1.x = 150; p1.y = 100;
// 	p2.x = 100; p2.y = 150;
// 	draw_line(mlx, window, p1, p2);
// }

// void	draw_letter_Y(void *mlx, void *window)
// {
// 	t_point p1, p2;

// 	// Верхняя левая линия для Y
// 	p1.x = 200; p1.y = 100;
// 	p2.x = 225; p2.y = 125;
// 	draw_line(mlx, window, p1, p2);

// 	// Верхняя правая линия для Y
// 	p1.x = 250; p1.y = 100;
// 	p2.x = 225; p2.y = 125;
// 	draw_line(mlx, window, p1, p2);

// 	// Нижняя вертикальная линия для Y
// 	p1.x = 225; p1.y = 125;
// 	p2.x = 225; p2.y = 150;
// 	draw_line(mlx, window, p1, p2);
// }

// void	draw_letter_J(void *mlx, void *window)
// {
// 	t_point p1, p2;

// 	// Вертикальная линия для Й
// 	p1.x = 300; p1.y = 100;
// 	p2.x = 300; p2.y = 150;
// 	draw_line(mlx, window, p1, p2);

// 	// Полукруглая часть для Й
// 	p1.x = 300; p1.y = 150;
// 	p2.x = 325; p2.y = 150;
// 	draw_line(mlx, window, p1, p2);

// 	// Горизонтальная линия над Й (для "шапочки")
// 	p1.x = 290; p1.y = 90;
// 	p2.x = 310; p2.y = 90;
// 	draw_line(mlx, window, p1, p2);
// }

// int	key_hook(int keycode, void *param)
// {
// 	if (keycode == 65307)
// 		exit(0);
// 	return (0);
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*window;

// 	mlx = mlx_init();
// 	if (mlx == NULL)
// 		return (1);
// 	window = mlx_new_window(mlx, 400, 200, "Draw HUI");
// 	if (window == NULL)
// 		return (1);

// 	// Рисуем буквы
// 	draw_letter_X(mlx, window);
// 	draw_letter_Y(mlx, window);
// 	draw_letter_J(mlx, window);

// 	mlx_key_hook(window, key_hook, NULL);
// 	mlx_loop(mlx);
// 	return (0);
// }
