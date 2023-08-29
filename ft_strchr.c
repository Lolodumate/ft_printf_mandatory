#include "libft.h"

char *ft_strchr(const char *s, int c)
{
	int		i;
	char	*str;

	i = 0;
	str = (char * )s;
	while (str[i])
	{
		if ((char)c == str[i])
			return (&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return (str);
	return (NULL);
}
