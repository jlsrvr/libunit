#ifndef TESTS_H
# define TESTS_H
# include "libunit.h"
# include "unistd.h"
# include "stdio.h"

typedef struct s_test
{
	int one;
	char two;
	char *three;
} t_test;

int basic_launcher(void);
int OK_test(void *params);
int KO_test(void *params);
int segv_test(void *params);
int timeout_test(void *params);
int fpe_test(void *params);
int bus_test(void *params);
int sigabort_test(void *params);

int params_launcher(void);
int one_params_test(void *value);
int struct_params_test(void *params);
int struct_segfault_test(void *params);

int output_launcher(void);
int pass_output_test(void *value);
int diff_test(void *value);
int diff_display_fail_test(void *value);
int diff_display_pass_test(void *value);
#endif
