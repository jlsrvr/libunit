#include "libunit.h"

static int	exec_test(int (*test)(void))
{
	int		status;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (FORK);
	status = 0;
	if (pid == 0)
	{
		alarm(TIME_LIMIT);
		exit(test());
	}
	wait(&status);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (UNKNOWN);
}

static void	print_result(int code)
{
	int		codes[9] = {SUCCESS, FAILURE, FORK, UNKNOWN,
					SIGBUS, SIGABRT, SIGSEGV, SIGALRM, SIGFPE};
	char	strings[][22] = {"\e[32m[OK]", "\e[31m[KO]", "\e[31mFramework failure",
				"\e[31m[Crash]", "\e[31m[BUSE]", "\e[31m[SIGA]",
				"\e[31m[SEGV]", "\e[31m[TIMEOUT]", "\e[31m[FPE]"};
	int		index;

	index = 0;
	while (index < 9 && code != codes[index])
		index++;
	printf("%s"RESET, strings[index]);
}

int	launch_tests(t_unit_lst **lst, char *title)
{
	int			test_count;
	int			passed;
	int			ret;
	t_unit_lst	*test_elem;

	if (!lst || !*lst)
		return (-1);
	test_count = 0;
	passed = 0;
	test_elem = *lst;
	printf(CYAN UNDER"%s:"RESET, title);
	while (test_elem)
	{
		test_count++;
		printf("\n    >%-*.*s : ", DISPLAY_SIZE,
			DISPLAY_SIZE, test_elem->describe);
		fflush(stdout);
		ret = exec_test(test_elem->test);
		if (ret == 0)
			passed++;
		print_result(ret);
		test_elem = test_elem->next;
	}
	clean_tests(lst);
	printf(CYAN"\n\t%d/%d tests passed\n", passed, test_count);
	return (passed == test_count);
}
