#include "tests.h"
#include <assert.h>

int sigabort_test(void)
{
	char* foo = NULL;
	assert( foo != NULL );
	return (0);
}
