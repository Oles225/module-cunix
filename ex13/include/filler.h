#ifndef _FILLER_H_
#define _FILLER_H_

#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <stdlib.h>

typedef struct  map_s
{
  int           h;
  int           w;
  char          **array;
}               map_t;

typedef struct  elem_s
{
  int           h;
  int           w;
  char          **array;
}               elem_t;

typedef struct  pos_s
{
  int           x;
  int           y;
}               pos_t;

typedef struct  req_s
{
  char          symbol;
  map_t         map;
  elem_t        elem;
}               req_t;

typedef struct  stream_s
{
  char          *str;
  unsigned int  size;
  unsigned int  limit;
}               stream_t;

/*Functions for parsing*/
req_t*          read_all(void);

/*Functions for game logic*/
pos_t           play(req_t *core);
void            game(void);

/*Functions for printing*/
void            print_pos(pos_t p);

/*Tools*/
req_t           *create_req(req_t *req);
void            destroy_req(req_t *req);
#endif // _FILLER_H_