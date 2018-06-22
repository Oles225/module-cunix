#include "minishell.h"

int   buildins(hashtable_t *ht, char **command, char *input)
{
  if (!command[0]){
    free(input);
    free(command);
    return (1);
  }
  if (strcmp(command[0], "cd") == 0) {
    if (chdir(command[1]) < 0) {
      perror(command[1]);
    }
    return (1);
  }
  if (strcmp(command[0], "env") == 0) {
    my_env(ht);
    return (1);
  }
  if (strcmp(command[0], "export") == 0) {
    my_export(ht, input);
    return (1);
  }
  if (strcmp(command[0], "exit") == 0) {
    free(input);
    free(command);
    exit(1);
  }
  return (0);
}