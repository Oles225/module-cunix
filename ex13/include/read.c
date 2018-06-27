#include "filler.h"
#include "my_string.h"

int   set_nonblocking(int fd)
{
  int   fl;
  int   snb;

  fl = fcntl(fd, F_GETFL, 0);
  snb = fcntl(fd, F_SETFL, fl | O_NONBLOCK);
  return (snb);
}

void  read_input(filler_t *filler)
{
  char  str[BUF_SIZE];
  int   res;

  while(1)
  {
    res = read(0, str, BUF_SIZE);
    str[res] = '\0';
    string_append(filler->current_stream, str);
    if (strlen(str) < BUF_SIZE)
      break;
  }
}