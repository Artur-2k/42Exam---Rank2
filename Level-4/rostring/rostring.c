#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

int is_white_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v' || c == '\0')
		return 1;
	return 0;
}
int main(int ac, char** av)
{
	if (ac < 2 || !av[1])
		return (write(1, "\n", 1), 0);

	int i = 0;
	while (av[1][i] && is_white_space(av[1][i]))
		i++;
	while(av[1][i]&& !is_white_space(av[1][i]))
		i++;

	int space = 0;
	while (av[1][i])
	{
		while (av[1][i] && is_white_space(av[1][i]))
			i++;
		while(av[1][i] && !is_white_space(av[1][i]))
		{
			write(1, &av[1][i++], 1);
			space = 1;
		}
		if (space)
		{
			space = 0;
			write(1, " ", 1);
		}
	}

	i = 0;
	while (av[1][i] && is_white_space(av[1][i]))
		i++;
	while(av[1][i] && !is_white_space(av[1][i]))
		write(1, &av[1][i++], 1);

	write(1, "\n", 1);
	return 0;
}