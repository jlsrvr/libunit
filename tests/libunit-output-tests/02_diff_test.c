#include "tests.h"

static int dummy_function(char *str)
{
	return (printf("%s", str));
}

int diff_test(void *p)
{
	char *exp;
	int ret;
	t_fd *std_out;

	exp = (char *)p;
	std_out = redirect_stdout("outputs/diff_test.log");
	ret = dummy_function("Pass");
	reverse_redirect(std_out);
	FILE *ptr = fopen("outputs/expected.log", "w");
	fprintf(ptr, "%s", exp);
	fclose(ptr);
	return (file_diff("outputs/diff_test.log", "outputs/expected.log"));
}
