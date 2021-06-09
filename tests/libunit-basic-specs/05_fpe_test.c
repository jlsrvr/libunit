#include "tests.h"

int fpe_test(void *params)
{
	(void)params;
	int a = 1;
	int result;

	result = a / (a - 1);
	return (0);
}
