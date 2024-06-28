#include <unistd.h>
#include <stdarg.h>
#include <stdlib.h>


int snake_word_count(const char *str)
{
	int count = 0;

	if (*str != 0 && *str != '_')
		count++;

	while (*str)
	{
		if (*str == '_' && *(str + 1) != '_' && *(str + 1) != '\0')
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
	write(1, "\n", 1);
}


int main(int ac, char **av)
{
	if (ac !=2 || !av[1] || !av[1][0])
	{
		write(1, "\n", 1);
		return (0);
	}
	int len = snake_word_count(av[1]);

	char *camel = (char *)malloc(sizeof(char) * (ft_strlen(av[1]) - len + 1));

	int i = 0;
	int j = 0;
	while (av[1][i])
	{
		if (av[1][i] == '_')
		{
			i++;
			camel[j] = av[1][i];
			if ('a' <= camel[j] && camel[j] <= 'z')
				camel[j] -= 32;
			j++;
			i++;
		}
		else
			camel[j++] = av[1][i++];
	}
	camel[j] = 0;

	ft_putstr(camel);
	free(camel);
	return (0);
}