/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:18:00 by laroges           #+#    #+#             */
/*   Updated: 2023/08/30 19:00:20 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_sign(int n)
{
	if (n < 0)
		return (1);
	return (0);
}

static size_t	ft_longlen(long long n)
{
	size_t	len;

	len = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		n *= -1;
	while (n > 0)
	{
		len++;
		n /= 10;
	}
	return (len);
}

static char	*ft_fill_int_in_str(char *str, long long n, size_t len, size_t i)
{
	while (len > i)
	{
		str[len - 1] = '0' + n % 10;
		n /= 10;
		len--;
	}
	return (str);
}

char	*ft_itoa(int n)
{
	size_t		len;
	long long	long_n;
	char		*str;

	long_n = n;
	len = ft_longlen(n) + ft_sign(long_n);
	str = malloc(sizeof(char) * len + 1);
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
	if (n < 0)
	{
		str[0] = '-';
		long_n *= -1;
	}
	ft_fill_int_in_str(str, long_n, len, ft_sign(n));
	return (str);
}
