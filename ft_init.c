#include "ft_printf.h"

t_tab	*ft_init(t_tab *init)
{
	init->index = 0;
	init->conversion = 0;
	return (init);
}
