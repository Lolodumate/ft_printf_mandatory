/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 13:28:48 by laroges           #+#    #+#             */
/*   Updated: 2023/08/30 18:48:06 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"

int	ft_conversion(t_tab *init, const char *format, int i)
{
	int	len;

	len = 0;
	if (ft_strchr("cspdiuxX%", format[i]))
	{
		if (format[i] == 'c')
			len += ft_print_char(va_arg(init->args, int));
		else if (format[i] == 's')
			len += ft_print_str(va_arg(init->args, char *));
		else if (format[i] == 'p')
			len += ft_print_ptr(va_arg(init->args, unsigned long long));
		else if (format[i] == 'd' || format[i] == 'i')
			len += ft_print_int(va_arg(init->args, int));
		else if (format[i] == 'u')
			len += ft_print_uint(va_arg(init->args, unsigned int));
		else if (format[i] == 'x' || format[i] == 'X')
			len += ft_print_hexa(va_arg(init->args, unsigned int), format[i]);
		else if (format[i] == '%' && format[i - 1] == '%')
			len += write(1, "%", 1);
		i++;
		init->index = i;
	}
	return (len);
}

int	ft_printf(const char *format, ...)
{
	int		len_format;
	t_tab	*init;

	len_format = 0;
	init = malloc(sizeof(t_tab));
	if (init == NULL)
		return (-1);
	ft_init(init);
	va_start(init->args, format);
	len_format = ft_len_format(init, format);
	va_end(init->args);
	free(init);
	return (len_format);
}
