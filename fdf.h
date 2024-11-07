/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 14:20:42 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/06 14:11:53 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

#include "./Libft/src/libft.h"
#include <math.h>
#include <mlx.h>

typedef struct s_fdf_data
{
	int	map_size_x;
	int	map_size_y;
	int	**z_matrix;
}	t_data;

void	first_step(char *str);

#endif
