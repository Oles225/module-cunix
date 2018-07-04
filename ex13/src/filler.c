#include "filler.h"
#include "my_string.h"

void  create_filler(filler_t *filler)
{
  filler_t *new_fill;

  new_fill = (filler_t *)malloc(sizeof(filler_t));
  new_fill->status = 0;
  new_fill->find_enemy = 0;
}

void  destroy_filler(filler_t *filler)
{
  string_destroy(filler->current_stream);
  free(filler);
}

void  create_req(req_t *req)
{
  req_t *new_req;

  new_req = (req_t *)malloc(sizeof(req_t));
}

void  destroy_req(req_t *req)
{
  free(req);
}

int   main(void)
{
  fillet_t  *filler;

  create_filler(filler);
  start_game(filler);
  destroy_filler(filler);
  return (0);
}