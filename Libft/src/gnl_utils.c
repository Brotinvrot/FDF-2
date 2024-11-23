/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:09:27 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/06 10:52:59 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_n(char *line)
{
	int	i;

	i = 0;
	if (line == NULL)
		return (1);
	while (line[i])
	{
		if (line[i] == '\n')
			return (0);
		i++;
	}
	return (1);
}

void	get_clean(char **line, char *patteren)
{
	char	*new_line;
	int		i_pat;
	int		i_lin;

	i_pat = ft_strlen(patteren);
	i_lin = ft_strlen(*line);
	if (i_pat == i_lin)
	{
		free(*line);
		*line = NULL;
	}
	else
	{
		new_line = ft_strdup(*line + i_pat);
		free(*line);
		*line = new_line;
	}
}

char	*str_until_char(char *str, char c)
{
	char	*result;
	char	*pos;
	size_t	len;

	pos = ft_strchr(str, c);
	if (!pos)
		return (str);
	pos++;
	len = pos - str;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	ft_strncpy(result, str, len);
	result[len] = '\0';
	return (result);
}
