#include "minishell.h"

void  child(pid_t child_pid, char **command)
{
  int   stat_loc;

  if (child_pid < 0)
  {
    perror("Fork failed");
    exit(1);
  }
  if (child_pid == 0)
  {
    if (execvp(command[0], command) < 0)
    {
      perror(command[0]);
      exit(1);
    }
    printf("This won't be printed if execvp is successul\n");
  }
  else
    waitpid(child_pid, &stat_loc, WUNTRACED);
}

int   main(void)
{
  char  **command;
  char  *input;
  pid_t child_pid;

  while (1)
  {
    input = readline("$_> ");
    command = get_input(input);
    if (!command[0])
    {
      free(input);
      free(command);
      continue;
    }
    if (strcmp(command[0], "cd") == 0) {
      if (chdir(command[1]) < 0) {
        perror(command[1]);
      }
      continue;
    }
    if (strcmp(command[0], "exit") == 0)
    {
      free(input);
      free(command);
      exit(1);
    }
    child_pid = fork();
    child(child_pid, command);
  }
  return (0);
}