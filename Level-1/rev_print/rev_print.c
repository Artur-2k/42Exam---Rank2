# include <unistd.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	rev_print(char *str)
{
	int index= ft_strlen(str) - 1;

	while (index >= 0)
	{
		write(1, &str[index], 1);
		index--;
	}
	write(1, "\n", 1);
}

int	main(int ac, char **av)
{
	if (ac != 2 || !av[1] || !av[1][0])
	{
		write(1, "\n", 1);
		return (0);
	}

	rev_print(av[1]);
	return (0);
}