/* $Id: slab_alloc.h,v 1.1.1.1 2005/02/19 19:06:44 maqui Exp $ */

#include <sys/types.h>          /* size_t */

char *SlabStringAlloc(size_t size);
void SlabStringAllocDup(char **old, char *new, size_t max_len);
void SlabStringFree(char *string);
