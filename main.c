/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:55:04 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/18 13:51:21 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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
