NAME = minishell

C_FILES =	main.c str_replace.c store_env.c env_list_utils.c input.c parse_input.c \
			replace_var_names.c split_split.c pipe_split.c exec.c child.c split_split_utils.c

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

.PHONY: all clean fclean re
