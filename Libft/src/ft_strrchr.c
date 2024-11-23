/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:05:15 by drabadan          #+#    #+#             */
/*   Updated: 2023/11/18 13:22:28 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int n)
{
	int	i;
	int	box;

	if (n == '\0')
		return ((char *)s + ft_strlen(s));
	i = 0;
	box = -1;
	while (s[i])
	{
		if (s[i] == (unsigned char )n)
			box = i;
		i++;
	}
	if (box >= 0)
		return ((char *)s + box);
	return (NULL);
}
