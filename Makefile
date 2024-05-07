# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/05/07 13:30:00 by yinhong           #+#    #+#              #
#    Updated: 2024/05/07 15:28:39 by yinhong          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
LIBFT = libft.a
EXEC = ft_printf

SRCDIR = src/
LIBFTDIR = ./libft
# Fix later because apparently I cannot use wildcard
SRCS = $(wildcard $(SRCDIR)*.c)
OBJS = $(SRCS:.c=.o)

AR = ar
ARFLAGS = rcs

CC = cc
CFLAGS = -Wall -Werror -Wextra

RM = rm -f


all : $(NAME)

$(NAME) : $(OBJS)
	make -C $(LIBFTDIR)
	cp $(LIBFTDIR)/$(LIBFT) .
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

$(SRCDIR)%.o : $(SRCDIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@

exec : $(OBJS)
	@pwd
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(LIBFT)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXEC) $(LIBFT)
	make -C $(LIBFTDIR) fclean

re: fclean all