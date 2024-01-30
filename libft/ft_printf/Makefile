# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/09/16 11:23:29 by ketrevis          #+#    #+#              #
#    Updated: 2023/12/16 20:54:47 by ketrevis         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

SRC = ft_printf.c ft_putaddr_len.c ft_putchar_len.c ft_putnbr_len.c ft_putstr_len.c ft_strlen.c ft_uppercase.c

OBJS = $(SRC:.c=.o)

CC = cc
CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME):
	$(CC) $(CFLAGS) -c $(SRC)
	ar -rc $(NAME) $(OBJS)

clean:
	rm -f $(OBJS_BONUS) $(OBJS) 

fclean: clean
	rm -f $(NAME)

re: fclean all
