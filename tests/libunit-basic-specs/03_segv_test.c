#include "tests.h"

int segv_test(void)
{
	char *ptr;

	ptr = NULL;
	ptr[1] = 'J';
	return (0);
}
