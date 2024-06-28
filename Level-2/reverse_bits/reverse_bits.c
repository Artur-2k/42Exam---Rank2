unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char newByte = 0;
	unsigned char bit = 0;
	int i = 8;

	while (i)
	{
		bit = octet & 1; // gets the rightmost bit from octet

		newByte <<= 1; // opens up space for the new bit

		newByte |= bit; // as the rightmost bit is now 0 if bit is 1 we get 1 or 0 if bit is 0

		octet >>= 1; // skips to the next bit of the octet

		i--;
	}

}