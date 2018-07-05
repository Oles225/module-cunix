#include "filler.h"
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

void  read_symbol(req_t *req)
{
  char  symbol[2];
  int   sgn;

  sgn = read(0, symbol, 1);
  req->symbol = *symbol;
  read(0, symbol, 1);
}

void   read_map(req_t *req)
{
  map_t mp;
  int   h;
  int   w;
  char  *ch;
  char  *ch_bgn;

  ch = malloc(sizeof(char) * 5);
  ch_bgn = ch;
  read(0, ch, 1);
  while (*ch != ' ')
  {
    ch++;
    read(0, ch, 1);
  }
  *ch = '\0';
  h = atoi(ch_bgn);
  mp.h = h;
  mp.array = (char **)malloc(h * sizeof(char *));
  ch = ch_bgn;
  read(0, ch, 1);
  while(*ch != '\n')
  {
    ch++;
    read(0, ch, 1);
  }
  *ch = '\0';
  w = atoi(ch_bgn);
  mp.w = w;
  for (int i = 0; i < h; i++)
  {
    mp.array[i] = (char *)malloc((w + 1) * sizeof(char));
    read(0, mp.array[i], w + 1);
  }
  req->map = mp;
}

void  read_elem(req_t *req)
{
  elem_t  el;
  int     h;
  int     w;
  char    *ch;
  char    *ch_bgn;

  ch = malloc(sizeof(char) * 5);
  ch_bgn = ch;
  read(0, ch, 1);
  while (*ch != ' ')
  {
    ch++;
    read(0, ch, 1);
  }
  *ch = '\0';
  h = atoi(ch_bgn);
  el.h = h;
  el.array = (char **)malloc(h * sizeof(char *));
  ch = ch_bgn;
  read(0, ch, 1);
  while(*ch != '\n')
  {
    ch++;
    read(0, ch, 1);
  }
  *ch = '\0';
  w = atoi(ch_bgn);
  el.w = w;
  for (int i = 0; i < h; i++)
  {
    el.array[i] = (char *)malloc((w + 1) * sizeof(char));
    read(0, el.array[i], w + 1);
  }
  req->elem = el;
}

req_t  *read_all()
{
  req_t   *req;

  req = NULL;
  req = create_req(req);
  read_symbol(req);
  read_map(req);
  read_elem(req);
  return (req);
}
