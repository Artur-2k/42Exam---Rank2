# include <unistd.h>

int is_multiple_of_3(int a)
{
	if (a % 3 == 0)
		return (1);
	return (0);
}

int is_multiple_of_5(int a)
{
	if (a % 5 == 0)
		return (1);
	return (0);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void	ft_putnumb(int a)
{
	if (a < 10)
		ft_putchar(a + 48);
	else
	{
		ft_putnumb(a / 10);
		ft_putnumb(a % 10);
	}
}

int main(void)
{
	int	i;

	i = 1;
	while (i <= 100)
	{
		if (is_multiple_of_3(i) || is_multiple_of_5(i))
		{
			if (is_multiple_of_3(i))
			{
				if (is_multiple_of_5(i))
					write(1, "fizzbuzz", 8);
				else
					write(1, "fizz", 4);
			}
			else
				write(1, "buzz", 4);
		}
		else
			ft_putnumb(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}