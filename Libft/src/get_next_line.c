/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/05 16:06:50 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/11 14:27:34 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*join_and_free(char *line, char *bufer)
{
	char	*temp;

	temp = line;
	line = ft_strjoin(line, bufer);
	free(temp);
	return (line);
}

char	*read_and_update(int fd, char *line, int *bit)
{
	char	*buffer;
	int		read_check;

	buffer = malloc(BUFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	read_check = read(fd, buffer, BUFER_SIZE);
	*bit = read_check;
	if (read_check <= 0)
	{
		free(buffer);
		if (*line != '\0' && read_check == 0)
			return (line);
		if (*line != '\0')
			return (line);
		free(line);
		return (NULL);
	}
	buffer[read_check] = '\0';
	line = join_and_free(line, buffer);
	free(buffer);
	return (line);
}

char	*get_next_line(int fd)
{
	char		*result;
	char		*line;
	int			bit;
	static char	last_read[BUFER_SIZE + 1];

	line = ft_strdup(last_read);
	last_read[0] = '\0';
	bit = 1;
	while (find_n(line) != 0 && bit > 0)
	{
		line = read_and_update(fd, line, &bit);
		if (bit == 0)
		{
			last_read[0] = '\0';
			return (line);
		}
	}
	result = str_until_char(line, '\n');
	get_clean(&line, result);
	if (line)
		ft_strcpy(last_read, line);
	free (line);
	return (result);
}
