#include "header.h"

char  *new_format(char *format)
{
  while (*format != 's' || *format != 'd')
    format++;
  return (format);
}

int   padding(char *format)
{
  int padd;

  padd = 0;
  padd = my_atoi(format);
  return (padd);
}
