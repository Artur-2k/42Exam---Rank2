#include <unistd.h>
#include <stdarg.h>

int	get_index(char c)
{
	char *low_alphabet = "abcdefghijklmnopqrstuvwxyz";
	char *cap_alphabet = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	int	i = 0;

	if ('A' <= c && c <= 'Z')
	{
		while (cap_alphabet[i] != c)
			i++;
	}
	else if ('a' <= c && c <= 'z')
	{
		while (low_alphabet[i] != c)
			i++;
	}
	return (i);
}


int	main(int ac, char **av)
{
	if (ac != 2)
	{
		write(1, "\n", 1);
		return (0);
	}

	int i = 0;
	int repeat = 0;
	while (av[1][i])
	{
		repeat = get_index(av[1][i]) + 1;
		while (repeat--)
			write(1, &av[1][i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}