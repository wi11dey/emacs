#include "usage.h"

#include <stdlib.h>

void *xmalloc(size_t size)
{
	void *ret = malloc(size);
	if (!ret)
		die("Out of memory");
	return ret;
}
