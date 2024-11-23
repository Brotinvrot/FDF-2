/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:24:29 by drabadan          #+#    #+#             */
/*   Updated: 2023/11/18 15:54:06 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *need, size_t len)
{
	size_t	i;
	size_t	t;

	i = 0;
	t = 0;
	if (need[t] == '\0')
		return ((char *)hay);
	while (hay[i] && i < len)
	{
		t = 0;
		while (i + t < len && hay[i + t] == need[t] && need[t])
		{
			t++;
			if (need[t] == '\0')
				return ((char *)hay + i);
		}
		i++;
	}
	return (NULL);
}
