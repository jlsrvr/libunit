NAME		=	libunit_tests

CC			=	gcc

IDIR		=	-I./headers -I./../framework/headers

LIBS		=	-L./../framework -lunit

OBJS		=	$(SRC:.c=.o)

SRC 		=	runner.c \
				libunit-basic-specs/00_basic_launcher.c \
				libunit-basic-specs/01_OK_test.c \
				libunit-basic-specs/02_KO_test.c \
				libunit-basic-specs/03_segv_test.c \
				libunit-basic-specs/04_timeout_test.c \
				libunit-basic-specs/05_fpe_test.c \
				libunit-basic-specs/06_bus_test.c \
				libunit-basic-specs/07_sigabort_test.c \

RM			=	rm -f

FLAGS		=	-Wall -Wextra -Werror

.c.o:
	$(CC) $(FLAGS) $(IDIR) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	make_lib_unit $(OBJS)
			$(CC) $(FLAGS) -o $(NAME) $(OBJS) $(LIBS)
			echo ".gitignore" > .gitignore
			echo "minilibx-linux/test/mlx-test" >> .gitignore
			echo $(NAME) >> .gitignore
			find -type f -name "*.o" >> .gitignore
			find -type f -name "*.a" >> .gitignore
			sed -i -E 's/^\.\///' .gitignore

make_lib:
	@make libft.a -C ./libft/

make_lib_unit:
	@make -C ./../framework/

clean:
	$(RM) $(OBJS)
	@make clean -C ./libft/
	@make clean -C ./../framework/

fclean: 	clean
	$(RM) $(NAME)
	@make fclean -C ./libft/
	@make clean -C ./../framework/

re:			fclean all

.PHONY:	all clean fclean re make_lib_unit make_lib
