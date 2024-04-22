NAME = libftprintf.a
SRC = ft_printf.c
OBJS = $(SRC:.c=%.o)
AR = ar rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.c : %.o
	$(CC) $(CFLAGS) -c $<
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all