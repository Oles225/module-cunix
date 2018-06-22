#ifndef MINISHELL_H
# define MINISHELL_H

#include "linked_list.h"
#include "hash.h"
#include <stddef.h>  
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <string.h>
#include <readline/readline.h>
#include <unistd.h>
#include <sys/wait.h>

char  **get_input(char *input);
void  child(pid_t child_pid, char **command);
int   buildins(hashtable_t *ht, char **command, char *input);
int   my_export(hashtable_t *env, char *args);
int   my_env(hashtable_t *env);
int   proc_vars(hashtable_t *ht, char **input);

#endif

/*                                    Hints
 * Use "$_>" for prompt
 *
 * Note: if you want to use a hash to store shell vars, you must modify
 * both hash and linked_list to store keys, not only data
 *
 * It is better to start with export
 *
 * To print vars with env use next format:
 * "var_name: var_value"
 *
 * For ls use next format(printing in one line with one space as a delimiter):
 * "file1 file2 file3 "
 *
 * Use signal handler to handle Ctrl-C
 *
 *
 * Good luck)
*/
