#include <unistd.h>
#include <string.h>
#include <pthread.h>

typedef struct header_t mem_list;

struct header_t 
{
	size_t size;
	unsigned is_free;
	struct header_t *next;
};

mem_list *head = NULL;
mem_list *tail = NULL;

mem_list *get_free_block(size_t size)
{
	mem_list *curr;

  curr = head;
	while(curr) {
		if (curr->is_free && curr->size >= size)
			return curr;
		curr = curr->next;
	}
	return NULL;
}

void free(void *block)
{
	mem_list  *header;
  mem_list  *tmp;
	void      *prgbr;

	if (!block)
		return;
	header = (mem_list *)block - 1;
	prgbr = sbrk(0);
	if ((char *)block + header->size == prgbr)
  {
		if (head == tail)
      head = tail = NULL;
		else
    {
			tmp = head;
			while (tmp) {
				if(tmp->next == tail)
        {
					tmp->next = NULL;
					tail = tmp;
				}
				tmp = tmp->next;
			}
		}
		sbrk(0 - header->size - sizeof(mem_list));
		return;
	}
	header->is_free = 1;
}

void *halloc(size_t size)
{
	size_t     total_size;
	void      *block;
	mem_list  *header;

	if (!size)
		return NULL;
	header = get_free_block(size);
	if (header)
  {
		header->is_free = 0;
		return (void*)(header + 1);
	}
	total_size = sizeof(mem_list) + size;
	block = sbrk(total_size);
	if (block == (void*) -1)
		return NULL;
	header = block;
	header->size = size;
	header->is_free = 0;
	header->next = NULL;
	if (!head)
		head = header;
	if (tail)
		tail->next = header;
	tail = header;
	return (void*)(header + 1);
}
