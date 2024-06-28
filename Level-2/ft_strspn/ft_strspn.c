#include <stdlib.h>

int ft_is_in(char c, const char *str)
{
	int i = 0;
	while (*str)
	{
		if (c == *str)
			return (1);
		str++;
	}
	return (0);
}

size_t	ft_strspn(const char *s, const char *accept)
{
	size_t len = 0;

	while (*s)
	{
		if (!ft_is_in(*s, accept))
			return (len);
		else
			len++;
		s++;
	}
	return (len);
}
