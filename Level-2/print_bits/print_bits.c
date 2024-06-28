#include <unistd.h>

void	print_bits(unsigned char octet)
{
	unsigned char bit;
	int i = 7;

	while (i >= 0)
	{
		bit = (octet >> i & 1) + '0';
		write(1, &bit, 1);
		i--;
	}
}