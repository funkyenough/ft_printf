# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 13:30:00 by yinhong           #+#    #+#              #
#    Updated: 2024/05/09 10:21:22 by yinhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXEC = ft_printf

SRCDIR = src/
# Fix later because apparently I cannot use wildcard
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = rcs

CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f


all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$%.o : $%.c
	$(CC) $(CFLAGS) -c $< -o $@

exec : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)
	@echo "\nOutput of printf:\n-----------------------"
	@./ft_printf
	@echo "-----------------------"
	make fclean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXEC) $(LIBFT)

re: fclean all