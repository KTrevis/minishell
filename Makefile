NAME = minishell

C_FILES =	main.c parse_input.c split_env.c env_utils.c input.c shell_split.c \
			shell_split_utils.c ft_echo.c replace_var_split.c isolate_var_name.c

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
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
