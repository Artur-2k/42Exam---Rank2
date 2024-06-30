#include <unistd.h>
#include <stdarg.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_putnumb(int n)
{
	long nmb = n;
	if (nmb < 0)
	{
		nmb = -nmb;
		write(1, "-", 1);
	}
	if (nmb < 10)
		ft_putchar(nmb + '0');
	else
	{
		ft_putnumb(nmb / 10);
		ft_putnumb(nmb % 10);
	}
}
int main (int ac, char** av)
{
	if (ac < 2)
		return (write(1, "0\n", 2), 0);

	ft_putnumb(ac - 1);
	write(1, "\n", 1);
	return 0;
}