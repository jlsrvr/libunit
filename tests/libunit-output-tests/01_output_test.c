#include "tests.h"

static int dummy_function(char *str)
{
	return (printf("%s", str));
}

int pass_output_test(void *value)
{
	(void)value;
	int ret;
	t_fd *std_out;

	std_out = redirect_stdout("toto.log");
	ret = dummy_function("This should not appear");
	reverse_redirect(std_out);
	if (ret > 0)
		return (0);
	return (1);
}
