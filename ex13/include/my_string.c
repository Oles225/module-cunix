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
  int   len_1;
  int   len_2;
  int   i;

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
/*
void        string_append(stream_t *ptr, char *str)
{
  unsigned int    size;
  unsigned int    i;

  ptr->str = realloc(ptr->str, ptr->limit + BUF_SIZE);
  size = strlen(str);
  ptr->size += size;
  ptr->limit += size;
  for (i = 0; i < size; i++)
    ptr->str[ptr->size + i] = str[i];
  ptr->str[ptr->size + i] = '\0';
}
*/
void        string_destroy(stream_t *str)
{
  free(str->str);
  free(str);
}
/*
int main()
{
  stream_t *str2, *str1;

  str2 = string_init();

  string_append(str2, "Halllo");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, " there");
  string_append(str2, "tail");
  printf("%s\n", str2->str);
  printf("size: %d, len: %d, limit: %d\n", str2->size, (int)strlen(str2->str), str2->limit);
  str1 = string_create("tgggggggggggsgsgsgsggsgsggsgsgsggsggsgsgsgsgsgsggsgsgsgsgggsgsgsgsgsggsgsgsgsggsgsgsgsgsgsgsgsgsgsgsggsgsgsgsgsgsgsggsgsgsgsgsgsgsgsgsgsgsgsgsg`k");
  printf("%s\n", str1->str);
  printf("size: %d, len: %d, limit: %d\n", str1->size, (int)strlen(str1->str), str1->limit);
  string_destroy(str2);
  string_destroy(str1);
  return 0;
}
*/