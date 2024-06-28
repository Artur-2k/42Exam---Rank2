#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>

int camel_word_count(const char *str)
{
	int count = 0;

	while (*str)
	{
		if ('A' <= *str && *str <= 'Z')
			count++;
		str++;
	}
	return (count);
}
int	ft_strlen(const char *str)
{
	int i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}


int main(int ac, char **av)
{
	if (ac !=2 || !av[1] || !av[1][0])
	{
		write(1, "\n", 1);
		return (0);
	}
	int len = camel_word_count(av[1]);

	char *snake = (char *)malloc(sizeof(char) * (ft_strlen(av[1]) + len + 1));

	int i = 0;
	int j = 0;
	while (av[1][i])
	{
		if ('A' <= av[1][i] && av[1][i] <= 'Z')
			snake[j++] = '_';
		snake[j++] = av[1][i++];
	}
	snake[j] = 0;

	ft_putstr(snake);
	free(snake);
	return (0);
}