#include <stdarg.h>
#include <unistd.h>

int is_white_space(char c)
{
	if (c == '\t' || c == ' ' || c == '\n' || c == '\v')
		return 1;
	return 0;
}

void put_word(char *str)
{
	if (!str)
		return ;

	int space = 0;
	if (is_white_space(*str))
	{
		space = 1;
		str++;
	}
	while(*str && !is_white_space(*str))
	{
		write(1, str, 1);
		str++;
	}
	if (space)
		write(1, " ", 1);
}
int main(int ac, char** av)
{
	if (ac != 2 || !av[1] || ! av[1][0])
		return (write(1, "\n", 1), 0);

	int i = 0;
	int stopped = 0;

	while (av[1][i])
		i++;

	while (--i >= 0)
	{
		while (!is_white_space(av[1][i]))
		{
			if (i == 0)
				break ;
			i--;
		}
		put_word(&av[1][i]);
	}
	write(1, "\n", 1);
	return 0;
}