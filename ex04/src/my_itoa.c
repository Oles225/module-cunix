#include <stdlib.h>

char   *my_itoa(int nmb)
{
  char  *array;
  int   order;
  int   tmp_nmb;

  tmp_nmb = nmb;
  order = 1;
  while (tmp_nmb)
  {
    order++;
    tmp_nmb = tmp_nmb / 10;
  }
  array = malloc((order + 1) * sizeof(char));
  array[order] = '\0';
  if (nmb < 0)
  {
    array[0] = '-';
    nmb = -nmb;
  }
  while (order--)
  {
    array[order] = nmb % 10 + 48;
    nmb /= 10;
  }
  return (array);
}