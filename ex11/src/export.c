#include "minishell.h"

int   my_export(hashtable_t *env, char *args)
{
  char  *var;
  char  *value;
  char  *var_ptr;
  char  *value_ptr;

  var = malloc(32 * sizeof(char));
  value = malloc(128 * sizeof(char));
  var_ptr = var;
  value_ptr = value;

  while (*args && *args != '=')
  {
    if (*args == ' ')
    {
      args++;
      continue;
    }
    *var++ = *args++;
  }
  *var = '\0';

  if (*args == '\0')
    return (-1);

  args++;
  while (1)
  {
    if (*args == ' ' || *args == '\0')
    {
      *value = '\0';
      hash_set(env, var_ptr, value_ptr);
      return (0);
    }
    *value++ = *args++;
  }
  return (-1);
}

int my_env(hashtable_t *env)
{
  hash_print(env);
  return (0);
}