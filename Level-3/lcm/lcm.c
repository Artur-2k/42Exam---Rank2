unsigned int    lcm(unsigned int a, unsigned int b)
{
	if (!a || !b)
		return 0;
	unsigned int lcm = (a > b) ? b : a;
	while (1)
	{
		if (lcm % a == 0 && lcm % b == 0)
			return lcm;
		lcm++;
	}
}
