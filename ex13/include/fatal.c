#include "filit.h"

void  fatal(char  *msg)
{
  dprintf(2, msg);
  exit(1);
}