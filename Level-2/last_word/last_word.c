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
	if (ac != 2 || !av[1])
	{
		write(1, "\n", 1);
		return 0;
	}

	int len = 0;

	while (av[1][len])
		len++;;
	len--;

	while (len >= 0 && ft_is_in(av[1][len], " \n\t\v"))
		len--;

	while (len >= 0 && !ft_is_in(av[1][len], " \n\t\v"))
		len--;

	len++;
	if (!ft_is_in(av[1][len], " \n\t\v"))
	{
		while (av[1][len])
			write(1, &av[1][len++], 1);
	}
	
	write(1, "\n", 1);
	return 0;
}