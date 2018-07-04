#include "filler.h"

void   game(void)
{
  req_t *req;
  pos_t res;

  req = read_all();
  res = play(req);
  print_pos(res);
}