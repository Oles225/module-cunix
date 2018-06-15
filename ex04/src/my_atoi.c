char  *ft_iswhitespace(char *str)
{
  while (*str == ' ' || (*str >= 9 && *str <= 13))
		str++;
	return (str);
}

int   my_itoa(const char *nptr)
{
  char  *str;
  int   sign;
  int   nbr;

  str = (char *)nptr;
  str = ft_iswhitespace(str);
  sign = 1;
  if (*str == '+')
    str++;
  else
  {
    sign = -1;
    str++;
  }
  nbr = 0;
  while (*str && (*str >= '0') && (*str <= '9'))
  {
   nbr = nbr * 10 + *str - '0';
   str++;
  } 
  return ((int)(nbr * sign));
}