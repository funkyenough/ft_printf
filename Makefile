# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 13:30:00 by yinhong           #+#    #+#              #
#    Updated: 2024/05/09 10:52:13 by yinhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
EXEC = ft_printf

SRCS =  ft_print_char.c ft_print_hex.c ft_print_nbr.c ft_print_ptr.c ft_print_str.c ft_print_unbr.c ft_printf.c ft_utils.c
OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = rcs

CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f


all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

exec : $(OBJS)
	$(CC) $(CFLAGS) -c main.c -o main.o
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) main.o
	@echo "\nOutput of printf:\n-----------------------"
	@./ft_printf
	@echo "-----------------------"
	make fclean

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXEC) main.o

re: fclean all