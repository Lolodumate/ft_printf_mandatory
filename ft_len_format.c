#include "ft_printf.h"

int	ft_len_format(t_tab *init, const char *format)
{
	int	i;
	int	conversion;
	int	tmp;

	i = 0;
	conversion = 0;
	tmp = 0;
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			tmp++;
			conversion = ft_conversion(init, format, i);
			i = init->index - 1;
			if (conversion >= 0)
			{
				init->conversion += conversion;
				tmp++;
			}
			conversion = 0;
		}
		else
			ft_putchar(format[i]);
		i++;
	}
	return (ft_strlen(format) + init->conversion - tmp);
}
