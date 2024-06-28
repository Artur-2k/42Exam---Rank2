#include <unistd.h>
#include <stdarg.h>

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

int main(int ac, char** av)
{
	if (ac != 3 || !av[1]|| !av[2])
	{
		write(1, "\n", 1);
		return -1;
	}

	int i = 0;
	int j = 0;
	while (av[1][j] && av[2][i])
	{
		while(av[2][i] && av[1][j] != av[2][i])
			i++;
		if (av[1][j] == av[2][i])
		{
			i++;
			j++;
		}
	}

	if (!av[1][j])
		ft_putstr(av[1]);
	else
		write(1, "\n", 1);

	return 0;
}