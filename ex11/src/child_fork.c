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
    printf("This won't be printed if execvp is successul\n"    );
  }
  else
    waitpid(child_pid, &stat_loc, WUNTRACED);
}
