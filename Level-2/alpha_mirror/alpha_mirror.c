#include <unistd.h>
#include <stdarg.h>

int main(int ac, char **av)
{
	if (ac != 2 || !av[1] || !av[1][0])
	{
		write(1, "\n", 1);
		return (0);
	}

	int	i = 0;
	while (av[1][i])
	{
		if ('A' <= av[1][i] && av[1][i] <= 'Z')
			av[1][i] = 'Z' - av[1][i] + 'A';
		else if ('a' <= av[1][i] && av[1][i] <= 'z')
			av[1][i] = 'z' - av[1][i] + 'a';
		write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}