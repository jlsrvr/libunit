#include "tests.h"

int segv_test(void *params)
{
	(void)params;
	char *ptr;

	ptr = NULL;
	ptr[1] = 'J';
	return (0);
}
