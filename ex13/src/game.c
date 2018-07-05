#include "filler.h"

pos_t  *create_pos(pos_t *pos)
{
  pos = (pos_t *)malloc(sizeof(pos_t));
  pos->x = 0;
  pos->y = 0;
  return (pos);
}

pos_t  play(req_t *core)
{
  pos_t *pos;
  int   i;
 // int   j;

  pos = NULL;
  pos = create_pos(pos);
  i = 0;
// j = 0;
  printf("%c\n", core->symbol);
  printf("%d %d\n", core->map.h, core->map.w);
  while (i < core->map.h)
  {
    printf("%s", core->map.array[i]);
    i++;
  }
  printf("%d %d\n", core->elem.h, core->elem.w);
  i = 0;
  while (i < core->elem.h)
  {
    printf("%s", core->elem.array[i]);
    i++;
  }
  printf("Hello\n");
  return (*pos);
}


void   game(void)
{
  req_t *req;
  pos_t res;

  req = read_all();
  res = play(req);
  print_pos(res);
}