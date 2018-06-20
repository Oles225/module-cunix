#include "header.h"

void  padding_print(int padd, int null, char *s)
{
      if (padd)
      {
        padd -= strlen(s);
        while (padd--)
        {
          if (null)
            my_putchar('0');
          else
            my_putchar(' ');
        }
      }
}

char  *output(char *frmt, va_list arg, char *s)
{
    int   padd;
    int   null;

    null = 0;
    padd = padding(frmt);
    if (padd)
    {
      if (*frmt == '0')
        null = 1;
      while (isdigit(*frmt))
        frmt++; 
    }
    if (*frmt == 's')
    {
      s = va_arg(arg, char *);
      padding_print(padd, null, s);
      my_putstr(s);
   }
    else if (*frmt == 'd')
    {
      s = my_itoa(va_arg(arg, int));
      padding_print(padd, null, s);
      my_putstr(s);
    }
    else if (*frmt)
      my_putchar(*frmt);
    return (frmt);
}


int   my_printf(const char *format, ...)
{
  va_list arg;
  char    *s;
  char    *frmt;

  frmt = (char *)format;
  va_start(arg, format);
  while (*frmt)
  {
    while (*frmt && *frmt != '%')
    {
      my_putchar(*frmt);
      frmt++;
    }
    if (*frmt)
      frmt++;
    frmt = output(frmt, arg, s);
    if (*frmt)
      frmt++;
  }
  va_end(arg);
}