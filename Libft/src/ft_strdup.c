/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 11:16:08 by drabadan          #+#    #+#             */
/*   Updated: 2023/11/16 12:09:25 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*point;
	int		len_src;

	if (src == NULL)
		return (NULL);
	len_src = ft_strlen(src);
	point = (char *)malloc(len_src + 1);
	if (point == NULL)
		return (NULL);
	while (*src)
		*point++ = *src++;
	*point = '\0';
	return (point - len_src);
}
