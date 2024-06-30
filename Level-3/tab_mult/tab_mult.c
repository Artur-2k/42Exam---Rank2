#include <unistd.h>
#include <stdarg.h>

int	ft_atoi(const char *str)
{
	int sign = 1;
	int result = 0;

	while (*str == '\n' || *str == ' '
		|| *str == '\t' || *str == '\v' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}
void	ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_putnumb(int n)
{
	if (n < 10)
		ft_putchar(n + 48);
	else
	{
		ft_putnumb(n / 10);
		ft_putnumb(n % 10);
	}
}
int main(int ac, char ** av)
{
	if (ac != 2 || !av[1] || !av[1][0])
		return(write(1, "\n", 1), 0);

	int i= 1;
	int n = ft_atoi(av[1]);
	int res;
	while (i <= 9)
	{
		ft_putnumb(i);
		write(1, " x ", 3);
		ft_putnumb(n);
		write(1, " = ", 3);
		res = n * i;
		ft_putnumb(res);
		write(1, "\n", 1);
		i++;
	}
	return 0;
}