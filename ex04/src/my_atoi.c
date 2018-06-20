static char	*ft_iswhitespace(char *temp_str)
{
	while (*temp_str == ' ' || (*temp_str >= 9 && *temp_str <= 13))
		temp_str++;
	return (temp_str);
}

int		  my_atoi(const char *nptr)
{
	char				*temp_str;
	int					sign;
	unsigned long int	number;

	temp_str = (char *)nptr;
	sign = 1;
	number = 0;
	temp_str = ft_iswhitespace(temp_str);
	if (*temp_str == '+')
		temp_str++;
	else if (*temp_str == '-')
	{
		sign = -1;
		temp_str++;
	}
	while (*temp_str && (*temp_str >= '0') && (*temp_str <= '9'))
	{
		number = (number * 10) + (*temp_str - '0');
		temp_str++;
	}
	return ((int)(number * sign));
}