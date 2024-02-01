NAME = minishell

SRCS = main.c quote_split.c ft_echo.c input.c split_env.c env_list.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror -g3

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	cc $(CFLAGS) $(OBJS) -o $(NAME) libft/libft.a -lreadline

.c.o:
	cc $(CFLAGS) -c $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
