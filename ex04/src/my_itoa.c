#include <stdlib.h>
#include <string.h>

char   *my_itoa(int nmb)
{
  char  array[12];
  int   order;
  int   tmp_nmb;

  tmp_nmb = nmb;
  order = 1;
  while (tmp_nmb / 10)
  {
    order++;
    tmp_nmb = tmp_nmb / 10;
  }
  if (nmb < 0)
  {
    array[0] = '-';
    nmb = -nmb;
    array[order + 1] = '\0';
  } 
  else
    array[order] = '\0';
  while (order >= 1)
  {
    array[--order] = nmb % 10 + 48;
    nmb /= 10;
  }
  return (strdup(array));
}