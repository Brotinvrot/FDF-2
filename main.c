/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/18 20:55:04 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/26 17:42:07 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	line_check(char *line)
{
	int		i;
	int		size;
	char	**array;

	i = 0;
	size = 0;
	array = ft_split(line, ' ');
	while (array[i])
	{
		if (array[i])
			if ((array[i][0] >= '0' && array[i][0] <= '9') || \
				array[i][0] == '-')
				size++;
		free(array[i]);
		i++;
	}
	free(array);
	return (size);
}

int	main(int argc, char **argv)
{
	t_fdf	data;

	if (argc != 2)
	{
		write(2, "Do this: ./fdf <filename>\n", 26);
		return (1);
	}
	first_step(argv[1], &data);
	return (0);
}
