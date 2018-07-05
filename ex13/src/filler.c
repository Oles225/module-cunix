#include "filler.h"
#include "my_string.h"

req_t  *create_req(req_t *req)
{
  req_t *new_req;

  new_req = (req_t *)malloc(sizeof(req_t));
  req = new_req;
  return (req);
}

void    destroy_req(req_t *req)
{
  free(req);
}

int     main(int argc, char *argv[])
{

  game();
  return (0);
}