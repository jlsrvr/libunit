#include "tests.h"
#include <assert.h>

int sigabort_test(void *params)
{
	t_fd *temp;

	(void)params;
	char* foo = NULL;
	temp = redirect_stderr("outputs/stderr.log");
	assert( foo != NULL );
	reverse_redirect(temp);
	return (0);
}
