#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>

int main (int ac, char **av)
{
	if (ac != 4)
	{
		write(1, "\n", 1);
		return (0);
	}
	int a = atoi(av[1]);
	int b = atoi(av[3]);

	if (av[2][0] == '*')
		printf("%d\n", a * b);
	else if (av[2][0] == '+')
		printf("%d\n", a + b);
	else if (av[2][0] == '-')
		printf("%d\n", a - b);
	else if (av[2][0] == '/')
		printf("%d\n", a / b);
	else if (av[2][0] == '%')
		printf("%d\n", a % b);

	return (0);
}