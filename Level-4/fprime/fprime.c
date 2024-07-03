#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>

int main (int ac, char** av)
{
	if (ac != 2 || !av[1] || !av[1][0])
		return (printf("\n"), 0);

	int n = atoi(av[1]);
	if (n <= 0)
		return (printf("\n"), 0);
	if (n == 1)
		return(printf("1\n"), 0);
	int i = 2;
	while (n != 1)
	{
		if (n % i == 0)
		{
			n /= i;
			if (n == 1)
				printf("%d\n", i);
			else
				printf("%d*", i);
			i = 2;
		}
		else
			i++;
	}
	return 0;
}