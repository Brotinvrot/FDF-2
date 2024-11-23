/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drabadan <drabadan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 11:25:37 by drabadan          #+#    #+#             */
/*   Updated: 2024/11/01 13:51:02 by drabadan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_dig(int n)
{
	int	l;

	l = 0;
	if (n == -2147483648)
	{
		return (11);
	}
	if (n <= 0)
	{
		n *= -1;
		l++;
	}
	while (n > 0)
	{
		n = n / 10;
		l++;
	}
	return (l);
}

static int	int_min(char *str)
{
	str[0] = '-';
	str[1] = '2';
	return (147483648);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;

	len = count_dig(n);
	str = (char *)malloc(len + 1);
	if (!str)
		return (NULL);
	if (n == -2147483648)
		n = int_min(str);
	if (n < 0)
	{
		n = n * -1;
		str[0] = '-';
	}
	if (n == 0)
		str[0] = '0';
	str[len] = '\0';
	while (n > 0)
	{
		str[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (str);
}
