/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laroges <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 14:31:13 by laroges           #+#    #+#             */
/*   Updated: 2023/08/30 18:49:49 by laroges          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_tab
{
	va_list	args;
	int		index;
	int		conversion;
}	t_tab;

int			ft_printf(const char *format, ...);
int			ft_conversion(t_tab *init, const char *format, int i);
int			ft_len_format(t_tab *init, const char *format);
int			ft_print_char(char c);
int			ft_print_hexa(unsigned int hexa, char c);
int			ft_print_ptr(unsigned long long ptr);
int			ft_print_str(char *str);
int			ft_print_int(int args);
int			ft_print_uint(int args);
int			ft_intlen(int n);
void		ft_putchar(char c);
void		ft_putstr(char *str);
t_tab		*ft_init(t_tab *init);

#endif
