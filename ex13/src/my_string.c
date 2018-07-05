#include "my_string.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

stream_t    *string_init()
{
  stream_t  *stream;

  stream = (stream_t *)malloc(sizeof(stream_t));
  stream->size = 0;
  stream->limit = BUF_SIZE;
  stream->str = malloc(stream->limit);
  *(stream->str) = '\0';
  return (stream);
}

stream_t    *string_create(char *str)
{
  stream_t  *s;

  s = string_init();
  string_append(s, str);
  return (s);
}

void string_append(stream_t *ptr, char *str)
{
  unsigned int   len_1;
  unsigned int   len_2;
  unsigned int   i;

  len_1 = strlen(str);
//  if (len_1 == 0)
//  return;
  len_2 = ptr->size + len_1;
  while (len_2 > ptr->limit)
    ptr->limit *= 2;
  ptr->str = realloc(ptr->str, ptr->limit);
  for (i = 0; i <= len_1; i++)
    ptr->str[ptr->size + i] = str[i];
  ptr->size += len_1;
}

void        string_destroy(stream_t *str)
{
  free(str->str);
  free(str);
}