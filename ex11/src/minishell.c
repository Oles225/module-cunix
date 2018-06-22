#include "minishell.h"

int   main(void)
{
  char        **command;
  char        *input;
  pid_t       child_pid;
  hashtable_t *ht;

  ht = hash_create(64);
  while (1)
  {
    input = readline("$_> ");
    proc_vars(ht, &input);
    command = get_input(input);
    if (buildins(ht, command, input))
      continue;
    child_pid = fork();
    child(child_pid, command);
  }
  return (0);
}