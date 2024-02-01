NAME = minishell

C_FILES =	main.c

SRCS = $(addprefix srcs/,$(C_FILES))
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -I includes/ -g3

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	cc $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a -lreadline

.c.o:
	cc $(CFLAGS) -c $^ -o $@

clean:
	make -C libft/ clean
	rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	rm -f $(NAME)

re: fclean all
	make -C libft/ re

.PHONY: all clean fclean re
