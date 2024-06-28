#include <stdarg.h>
#include <unistd.h>

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

int main(int ac, char** av)
{
	if (ac != 3 || !av[1]|| !av[2])
	{
		write(1, "\n", 1);
		return -1;
	}

	int i = 0;
	char seen[256] = {0};

	while (av[1][i])
	{
		if (!seen[av[1][i]])
		{
			write(1, &av[1][i], 1);
			seen[av[1][i]] = 1;
		}
		i++;
	}
	i = 0;
	while (av[2][i])
	{
		if (!seen[av[2][i]])
		{
			write(1, &av[2][i], 1);
			seen[av[2][i]] = 1;
		}
		i++;
	}
	write(1, "\n", 1);
	return 0;
}