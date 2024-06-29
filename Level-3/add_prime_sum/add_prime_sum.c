#include <unistd.h>
#include <stdarg.h>

int is_prime(unsigned int n)
{
	if (n <= 1)
		return 0;

	unsigned int i = 2;
	while (i * i <= n)
	{
		if (n % i == 0)
			return 0;
		i++;
	}
	return (1);
}
void ft_putchar(int c)
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

int main(int ac, char** av)
{
	if (ac != 2 && !av[1])
	{
		write (1, "0\n", 2);
		return 0;
	}

	int n = ft_atoi(av[1]);

	if (n <= 0)
	{
		write(1, "0\n", 2);
		return 0;
	}

	int sum = 0;

	while (n > 1)
	{
		if (is_prime(n))
			sum += n;
		n--;
	}
	ft_putnumb(sum);
	ft_putchar('\n');
	return 0;
}