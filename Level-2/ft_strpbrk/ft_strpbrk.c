#include <stdlib.h>

char* ft_strpbrk(const char *s1, const char *s2)
{
	int i;
	while (*s1)
	{
		i = 0;
		while (s2[i])
		{
			if (s2[i] == *s1)
				return (s1);
			i++;
		}
		s1++;
	}

	return (NULL);
}