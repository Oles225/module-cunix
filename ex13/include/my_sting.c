#include "my_string.h"
#include <stdlib.h>
#include <string.h>

stream_t    *string_init()
{
  stream_t  *stream;

  stream = malloc(sizeof(stream_t));
  stream->str = NULL;
  stream->size = 0;
  stream->limit = 0;
  return (stream);
}

stream_t    *string_create(char *str)
{
  stream_t  *s;

  s = string_init();
  s = string_append(s, str);
  s->size = srtlen(s->str);
  return (str);
}

void        string_append(stream_t *ptr, char *str)
{
  unsigned int   size;

  ptr->str = realloc(prt->str, ptr->limit + BUF_SIZE);
  size = strlen(str);
  ptr->size += size;
  ptr->limit += size;
  for (int i = 0; i < size; i++)
    ptr->str[ptr->size + i] = str[i];
  prt->str[ptr->size + i] = '\0';
}

void        string_destroy(stream_t *str)
{
  free(str);
}