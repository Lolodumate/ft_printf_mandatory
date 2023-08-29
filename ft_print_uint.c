#include "ft_printf.h"

static void	ft_fill_ui(unsigned int res)
{
	if (res > 9)
	{
		ft_fill_ui(res / 10);
		ft_fill_ui(res % 10);
	}
	else
		ft_putchar(res + '0');
}

static int	ft_uintlen(unsigned int res)
{
	int	len;

	len = 0;
	while (res > 0)
	{
		len++;
		res /= 10;
	}
	return (len);
}

int	ft_print_uint(int args)
{
	unsigned int	res;

	res = 0;

	if (args == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (args > 0)
		res = args;
	else
		res = UINT_MAX + args + 1;
	ft_fill_ui(res);
	return (ft_uintlen(args));
}
