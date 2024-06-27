int	ft_atoi(const char *str)
{
	int sign = 1;
	int result = 0;

	while (*str == '\n' || *str == ' '
		|| *str == '\t' || *str == '\v' || *str == '\r')
	{
		str++;
	}
	if (*str == '-')
	{
		sign = -sign;
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	return (result * sign);
}