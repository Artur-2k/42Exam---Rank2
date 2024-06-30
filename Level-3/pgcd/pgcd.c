#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

int main(int ac, char** av)
{
	if (ac != 3 || !av[1] || !av[2] ||!av[1][0] || !av[2][0])
		return (printf("\n"), 0);

	unsigned int a = atoi(av[1]);
	unsigned int b = atoi(av[2]);
	int hcd = (a < b) ? a : b;

	while (1)
	{
		if (a % hcd == 0 && b % hcd == 0)
			break;
		hcd--;
	}
	printf("%d\n", hcd);
	return 0;
}