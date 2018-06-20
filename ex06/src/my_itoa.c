#include "header.h"

char    *array_malloc(char *array, int order, int nmb)
{
        if (nmb < 0)
        {
                array = malloc((order + 2) * sizeof(char));
        array[0] = '-';
                array[order + 1] = '\0';
        }
        else
        {
        {
                array = malloc((order + 1) * sizeof(char));
                array[order] = '\0';
        }
        return (array);
}
}
char   *my_itoa(int nmb)
{
  char  *array;
  int   order;
  int   tmp_nmb;
  int   sign;

  tmp_nmb = nmb;
  order = 1;
  sign = 1;
  while (tmp_nmb / 10)
  {
    order++;
    tmp_nmb = tmp_nmb / 10;
  }
  array = array_malloc(array, order, nmb);
  if (nmb < 0)
  {
          nmb = -nmb;
          sign = -1;
  }
  while (order >= 1)
  {
          if (sign == -1)
                  array[order--] = nmb % 10 + 48;
          else
                  array[--order] = nmb % 10 + 48;
          nmb /= 10;
  }
  return (array);
}
