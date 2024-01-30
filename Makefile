NAME = minishell

SRCS = main.c echo_split.c ft_echo.c input.c
OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft/
	cc $(CFLAGS) -lreadline $(OBJS) -o $(NAME) libft/libft.a

.c.o:
	cc $(CFLAGS) -c $^

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
