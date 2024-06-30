#include <unistd.h>
#include <stdarg.h>

int is_white_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == ' ')
		return 1;
	return 0;
}
char *capitalize_string(char *str)
{
	int i = 0;
	int flag = 1;

	while (str[i])
		i++;
	--i;

	while (i >= 0)
	{
		while (is_white_space(str[i]))
		{
				i--;
				flag = 1;
		}
		if (flag)
		{
			flag = !flag;
			if ('a' <= str[i] && str[i] <= 'z')
				str[i] -= 32;
		}
		else
		{
			if ('A' <= str[i] && str[i] <= 'Z')
				str[i] += 32;
		}
		i--;
	}
	return str;
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

#include <stdio.h>
int main(int ac, char** av)
{
	if (ac < 2)
		return (write(1, "\n", 1), 0);

	int i = 1;
	while (i < ac)
	{
		capitalize_string(av[i]);
		ft_putstr(av[i]);
		i++;
	}

	return 0;
}