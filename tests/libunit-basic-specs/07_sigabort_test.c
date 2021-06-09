#include "tests.h"
#include <assert.h>

int sigabort_test(void *params)
{
	(void)params;
	char* foo = NULL;
	assert( foo != NULL );
	return (0);
}
