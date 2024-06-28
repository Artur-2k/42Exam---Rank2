#include <stdlib.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	size_t i;
	size_t len;

	len = 0;
	while (*s)
	{
		i = 0;
		while (reject[i])
		{
			if (*s == reject[i])
				return len;
			i++;
		}
		len++;
		s++;
	}
}
