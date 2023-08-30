/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hexa.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:36:26 by laroges           #+#    #+#             */
/*   Updated: 2023/08/30 18:47:41 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hexalen(unsigned int hexa)
{
	int	len;

	len = 0;
	if (hexa == 0)
		len = 1;
	while (hexa > 0)
	{
		hexa /= 16;
		len++;
	}
	return (len);
}

static void	ft_puthexa(unsigned int hexa, char c)
{
	if (hexa >= 16)
	{
		ft_puthexa(hexa / 16, c);
		ft_puthexa(hexa % 16, c);
	}
	else
	{
		if (hexa < 10)
			ft_putchar(hexa + '0');
		else if (c == 'x')
			ft_putchar(hexa - 10 + 'a');
		else if (c == 'X')
			ft_putchar(hexa - 10 + 'A');
	}
}

int	ft_print_hexa(unsigned int hexa, char c)
{
	ft_puthexa(hexa, c);
	return (ft_hexalen(hexa));
}
