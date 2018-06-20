#include "header.h"

void    my_putchar(char c)
{
        write(1, &c, 1);
}

void    my_putstr(char const *s)
{
        if (s)
        {
                while (*s)
                        my_putchar(*s++);
        }
}
