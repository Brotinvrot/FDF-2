/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/17 11:07:49 by drabadan          #+#    #+#             */
/*   Updated: 2023/11/17 11:47:55 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *dst, int n, size_t len)
{
	size_t			i;
	unsigned char	*ptr;

	ptr = (unsigned char *)dst;
	i = 0;
	while (i < len)
	{
		ptr[i] = (unsigned char)n;
		i++;
	}
	return (dst);
}
