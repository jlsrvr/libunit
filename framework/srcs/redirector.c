#include "libunit.h"

static void *clean_fail(t_fd *my_fd)
{
	close(my_fd->copy_og);
	close(my_fd->file_fd);
	free(my_fd);
	return (NULL);
}

static t_fd *redirect_output(char *filepath, FILE *og_output)
{
	t_fd	*my_fd;

	my_fd = malloc(sizeof(*my_fd));
	if (!my_fd)
		return (NULL);
	my_fd->og_output = og_output;
	my_fd->file_fd = open(filepath, O_RDWR|O_CREAT|O_TRUNC, 0600);
    if (my_fd->file_fd == -1)
		return (clean_fail(my_fd));
    my_fd->copy_og = dup(fileno(og_output));
	if (my_fd->copy_og == -1)
		return (clean_fail(my_fd));
    if (dup2(my_fd->file_fd, fileno(og_output)) == -1)
		return (clean_fail(my_fd));
	return (my_fd);
}

void reverse_redirect(t_fd *my_fd)
{
	if (!my_fd)
		return ;
    fflush(my_fd->og_output);
	close(my_fd->file_fd);
    dup2(my_fd->copy_og, fileno(my_fd->og_output));
    close(my_fd->copy_og);
	free(my_fd);
}

t_fd	*redirect_stdout(char *filepath)
{
	return (redirect_output(filepath, stdout));
}

t_fd	*redirect_stderr(char *filepath)
{
	return (redirect_output(filepath, stderr));
}

