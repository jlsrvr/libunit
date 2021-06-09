#include "tests.h"

int one_params_test(void *value)
{
	if (*(int *)value)
		return (0);
	return (1);
}
