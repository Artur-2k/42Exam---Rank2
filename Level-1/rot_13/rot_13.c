#include <stdarg.h>
#include <unistd.h>

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

int main(int ac, char **av)
{
	if (ac != 2 || !av[1] || !av[1][0])
	{
		write(1, "\n", 1);
		return (0);
	}

	int c = 0;
	int i = 0;

	while (av[1][i])
	{
		if ('A' <= av[1][i] && av[1][i] <= 'Z')
		{
			c = ((av[1][i] -'A' + 13) % 26) + 'A';
			ft_putchar((char)c);
		}
		else if ('a' <= av[1][i] && av[1][i] <= 'z')
		{
			c = ((av[1][i] - 'a' + 13) % 26) + 'a';
			ft_putchar((char)c);
		}
		else
			ft_putchar(av[1][i]);
		i++;
	}
	return (0);
}