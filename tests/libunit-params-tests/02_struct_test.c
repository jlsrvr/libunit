#include "tests.h"

int struct_params_test(void *p)
{
	t_test *params = (t_test*)p;
	if (params->one && params->two == '1')
		return (0);
	return (1);
}
