int miniStrchr(int c, char *str, int str_base)
{
	while (*str && str_base)
	{

		if ('A' <= c && c <= 'Z')
			c += 32;
		if (c == *str)
			return 1;
		str++;
		str_base--;
	}
	return 0;
}
int is_white_space(char c)
{
	if (c == '\n' || c == '\t' || c == '\v' || c == ' ')
		return 1;
	return 0;
}
int	ft_atoi_base(const char *str, int str_base)
{
	char *base = "0123456789abcdef";

	if (0 > str_base || str_base > 16)
		return (0);

	int sign = 1;
	int result = 0;

	while (*str && is_white_space(*str))
		str++;

	if (*str == '-')
		sign = -1;

	while (*str && miniStrchr(*str, base, str_base))
	{
		if ('0' <= *str && *str <= '9')
			result = result * str_base + (*str - '0');
		else if ('a' <= *str && *str <= 'z')
			result = result * str_base + (*str - 'a' + 10);
		else
			result = result * str_base + (*str - 'A' + 10);
		str++;
	}

	return (result * sign);

}