/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 13:45:00 by drabadan          #+#    #+#             */
/*   Updated: 2023/11/20 10:49:01 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	word_counter(char const *s, char c)
{
	int	w;

	w = 0;
	while (*s != '\0')
	{
		if (*s != c)
		{
			w++;
			while (*s != '\0' && *s != c)
				s++;
		}
		else
			s++;
	}
	return (w);
}

void	put(char const *s, char c, char **result)
{
	int			j;
	const char	*start;

	j = 0;
	while (*s)
	{
		if (*s != c)
		{
			start = s;
			while (*s && *s != c)
				s++;
			result[j] = ft_substr(start, 0, s - start);
			if (!result[j++])
			{
				while (--j >= 0)
					free(result[j]);
				free(result);
				return ;
			}
		}
		else
			s++;
	}
	result[j] = NULL;
}

char	**ft_split(char const *s, char c)
{
	int		word_count;
	char	**result;

	word_count = word_counter(s, c);
	result = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (result == NULL)
		return (NULL);
	put(s, c, result);
	return (result);
}
