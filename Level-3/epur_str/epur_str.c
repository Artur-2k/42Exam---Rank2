#include <unistd.h>
#include <stdarg.h>

int is_white_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == ' ')
		return 1;
	return 0;
}
int main(int ac, char** av)
{
	if (ac != 2 || !av[1] || !av[1][0])
		return (write(1, "\n", 1), 0);

	int flag = 0;

	while (*av[1] && is_white_space(*av[1]))
		av[1]++;

	while(*av[1])
	{
		while (*av[1] && is_white_space(*av[1]))
		{
			flag = 1;
			av[1]++;
		}
		if (*av[1] && flag)
			write(1, " ", 1);
		while(*av[1] && !is_white_space(*av[1]))
		{
			flag = 0;
			write(1, &(*av[1]), 1);
			av[1]++;
		}
	}
	write(1 ,"\n", 1);
}