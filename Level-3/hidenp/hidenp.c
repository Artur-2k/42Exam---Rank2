#include <unistd.h>
#include <stdarg.h>

int main(int ac, char** av)
{
	if (ac != 3 || !av[1] || !av[2])
		return (write(1, "\n", 1), 0);

	int i = 0;
	int j = 0;

	while (av[1][i] && av[2][j])
	{
		while (av[2][j] && av[1][i] != av[2][j])
			j++;
		if (av[1][i] == av[2][j])
			i++;
	}
	if (!av[1][i])
		write(1, "1\n", 2);
	else
		write(1, "0\n", 2);
	return 0;
}
