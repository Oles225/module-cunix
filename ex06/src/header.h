#ifndef HEADER_H
# define HEADER_H

#include <unistd.h>                                        
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdarg.h>

char  *my_itoa(int nmb);
int   my_atoi(const char *nptr);
void  my_putstr(const char *s);
void    my_putchar(char c);
char *new_format(char *format);
int   padding(char *format);

#endif
