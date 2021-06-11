NAME			=	libunit.a

CC				=	clang

OBJS			=	$(SRCS:.c=.o)

IDIR			=	headers/

SRCS			= 	srcs/load_test.c \
					srcs/add_test_to_end.c \
					srcs/launch_tests.c \
					srcs/clean_tests.c \
					srcs/load_suite.c \
					srcs/run_suites.c \
					srcs/redirector.c \
					srcs/file_diff.c \
					srcs/get_next_line.c \

RM				=	rm -f

FLAGS			=	-Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAGS) -I$(IDIR) -c $< -o $(<:.c=.o)

$(NAME):	$(OBJS)
			ar rcs $(NAME) $(OBJS)
			@echo ".gitignore" >> .gitignore
			@echo $(NAME) >> .gitignore
			@find . -type f -name "*.o" >> .gitignore
			@find . -type f -name "*.a" >> .gitignore
			@sed -i -E 's/^\.\///' .gitignore

all:		$(NAME)

clean:
	$(RM) $(OBJS)

fclean: 	clean
	$(RM) $(NAME)

re:			fclean all

.PHONY:	all clean fclean re
