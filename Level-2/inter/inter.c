#include <unistd.h>
#include <stdarg.h>

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

	char seen[256] = {0};

	while (*av[1])
	{
		if (ft_is_in(*av[1], av[2]))
		{
			if (seen[*av[1]] == 0)
				write(1, &(*av[1]), 1);
		}
		seen[*av[1]] = 1;
		av[1]++;
	}
	write(1, "\n", 1);
	return 0;
}

