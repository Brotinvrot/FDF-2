/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:25:08 by drabadan          #+#    #+#             */
/*   Updated: 2023/11/20 07:37:40 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set_character(char c, char const *set)
{
	while (*set) 
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

static char	*put(size_t res_l, size_t start, char *s1)
{
	size_t	i;
	char	*res;

	res = (char *)malloc(res_l + 1);
	if (!res)
		return (NULL);
	i = 0;
	while (i < res_l)
	{
		res[i] = s1[start + i];
		i++;
	}
	res[res_l] = '\0';
	return (res);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	end;
	size_t	result_length;
	size_t	start;
	char	*result;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	while (s1[start] && is_set_character(s1[start], set))
		start++;
	end = start;
	while (s1[end])
		end++;
	while (end > start && is_set_character(s1[end - 1], set))
		end--;
	result_length = end - start;
	result = put(result_length, start, (char *)s1);
	if (!result)
		return (NULL);
	return (result);
}
