#include "minishell.h"

void  proc_drive(hashtable_t *ht, char **input, char *str_ptr, char *str)
{
  char *word;
  char *word_ptr;
  char *iptr;

  word_ptr = malloc(32 * sizeof(char));
  iptr = *input;
  while(*iptr)
  {
    if (*iptr == '$')
    {
      iptr++;
      word = word_ptr;
      while(*iptr != ' ' && *iptr)
        *word++ = *iptr++;
      *word = '\0';
      word = (char *)hash_get(ht, word_ptr);
      if(!word)
        continue;
      while(*word != '\0')
        *str++ = *word++;
      continue;
    }
    *str++ = *iptr++;
  }
  *str = '\0';
  *input = str_ptr;
}

int   proc_vars(hashtable_t *ht, char **input)
{
  char *str_ptr;
  char *str;

  str_ptr = malloc(512 * sizeof(char));
  str = str_ptr;
  proc_drive(ht, input, str_ptr, str);
  return 0;
}