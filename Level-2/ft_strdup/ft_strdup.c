#include <stdlib.h>

char    *ft_strdup(char *src)
{
	size_t len = 0;
	while (src[len])
		len++;

	char *dup = (char*)malloc(sizeof(char) * len + 1);
	if (!dup)
		return (NULL);

	len = 0;
	while (src[len])
		dup[len++] = src[len++];
	dup[len] = 0;

	return (dup);
}
