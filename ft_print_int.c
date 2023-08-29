#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_intlen(int n)
{
	int	len;

	len = 0;
	if (n == INT_MIN)
		len = 11;
	else
	{
		if (n < 0)
		{
			len++;
			n *= -1;
		}
		if (n == 0)
			len = 1;
		while (n > 0)
		{
			n /= 10;
			len++;
		}
	}
	return (len);
}

int	ft_print_int(int args)
{
	char	*str;

	str = ft_itoa(args);
	ft_putstr(str);
	free(str);
	return (ft_intlen(args));
}
