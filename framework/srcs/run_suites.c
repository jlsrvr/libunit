#include "libunit.h"

static void pass(void)
{
	printf(GREEN"\n *******      **        ********    ********\n/**////**    ****      **//////    **////// \n/**   /**   **//**    /**         /**       \n/*******   **  //**   /*********  /*********\n/**////   **********  ////////**  ////////**\n/**      /**//////**         /**         /**\n/**      /**     /**   ********    ******** \n//       //      //   ////////    //////// \n"RESET);
}

static void fail(void)
{
	printf(RED "\n ********     **         **     **      \n/**/////     ****       /**    /**      \n/**         **//**      /**    /**      \n/*******   **  //**     /**    /**      \n/**////   **********    /**    /**      \n/**      /**//////**    /**    /**      \n/**      /**     /**    /**    /********\n//       //      //     //     ////////\n");
}

static void	print_header(char *title)
{
	int	index;
	int	len;

	len = 0;
	index = -1;
	if (title)
		len = (int)strlen(title);
	while (++index < (len + 41))
		printf("*");
	printf("\n");
	printf("******       Unit Tests for %s       ******\n", title);
	index = -1;
	while (++index < (len + 41))
		printf("*");
	printf("\n");
}

static int	print_result(int total, int passed)
{
	if (total == passed)
	{
		pass();
		return (0);
	}
	fail();
	return (1);
}

int	run_suites(t_suite_lst **suites, char *title)
{
	int			pass_count;
	int			suite_count;
	t_suite_lst	*temp;

	print_header(title);
	temp = *suites;
	pass_count = 0;
	suite_count = 0;
	while (temp)
	{
		suite_count++;
		if (temp->suite())
			pass_count++;
		temp = temp->next;
	}
	return (print_result(suite_count, pass_count));
}
