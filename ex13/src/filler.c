#include "filler.h"
#include "my_string.h"

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
  game();
  return (0);
}