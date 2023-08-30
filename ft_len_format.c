/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_format.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 16:27:19 by laroges           #+#    #+#             */
/*   Updated: 2023/08/30 18:55:55 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len_format(t_tab *init, const char *format)
{
	int	i;
	int	tmp;

	i = 0;
	tmp = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			tmp += 2;
			init->conversion += ft_conversion(init, format, i);
			i = init->index - 1;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	return (ft_strlen(format) + init->conversion - tmp);
}
