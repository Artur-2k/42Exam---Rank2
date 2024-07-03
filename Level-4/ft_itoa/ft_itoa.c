#include <stdlib.h>
#include <stdio.h>

int nchars(int nbr)
{
	int count = 0;
	if (nbr <= 0)
		count++;
	while (nbr)
	{
		nbr /= 10;
		count++;
	}
	return count;
}

char	*ft_itoa(int nbr)
{
	int len = nchars(nbr);

	char *str = (char*)malloc(sizeof(char) * len + 1);
	if (!str)
		return NULL;

	char digit;
	int i = 0;
	if (nbr < 0)
	{
		str[i] = '-';
		nbr *= -1;
		i++;
	}
	str[len] = '\0';
	while (--len >= i)
	{
		digit = nbr % 10 + '0';
		nbr /= 10;
		str[len] = digit;
	}
	return str;
}

int main()
{
	char *str = ft_itoa(-12345);
	printf("%s\n" , str);
	free(str);
}