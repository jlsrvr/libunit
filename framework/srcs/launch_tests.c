#include "libunit.h"

static int	exec_test(t_unit_lst *test)
{
	int		status;
	int     (*test_to_execute)(void*);
	void	*test_params;
	pid_t	pid;

	pid = fork();
	if (pid == -1)
		return (FORK);
	status = 0;
	if (pid == 0)
	{
		test_to_execute = test->test;
		test_params = test->params;
		alarm(TIME_LIMIT);
		exit(test_to_execute(test_params));
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
	int			test_count = 0;
	int			passed = 0;
	int			ret;
	t_unit_lst	*test_elem;

	if (!lst || !*lst)
		return (-1);
	test_elem = *lst;
	printf(CYAN UNDER"%s:"RESET, title);
	while (test_elem)
	{
		test_count++;
		printf("\n    >%-*.*s : ", DISPLAY_SIZE,
			DISPLAY_SIZE, test_elem->describe);
		fflush(stdout);
		ret = exec_test(test_elem);
		if (ret == SUCCESS)
			passed++;
		print_result(ret);
		test_elem = test_elem->next;
	}
	clean_tests(lst);
	printf(PINK"\n\t%d/%d tests passed\n", passed, test_count);
	return (passed == test_count);
}
