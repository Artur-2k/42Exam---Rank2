#include <stdlib.h>

int ft_abs(int x)
{
	if (x < 0)
		return -x;
	return x;
}
int     *ft_range(int start, int end)
{
	int len = ft_abs(end - start) + 1;

	int *tab = (int *)malloc(sizeof(int) * len);

	*tab = end;

	int i = 0;
	while (start != end)
	{
		i++;

		if (end < start)
			end++;
		else
			end--;

		tab[i] = end;
	}

	return tab;
}
