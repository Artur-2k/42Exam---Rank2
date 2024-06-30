#include <unistd.h>
#include <stdarg.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_puthex(int n)
{
	if (n < 16)
	{
		if (n < 10)
			ft_putchar(n + '0');
		else
			ft_putchar(n - 10 + 'a');
	}
	else
	{
		ft_puthex(n / 16);
		ft_puthex(n % 16);
	}
}
int ft_atoi(char *str)
{
	int result = 0;
	while (*str)
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return result;
}

int main(int ac, char** av)
{
	if (ac != 2 || !av[1] || !av[1][0])
		return (write(1, "\n", 1), 0);

	ft_puthex(ft_atoi(av[1]));
	write(1, "\n", 1);

	return 0;
}