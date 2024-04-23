NAME = libftprintf.a
SRC = ft_printf.c ft_itoa.c
OBJS = $(SRC:.c=%.o)
AR = ar rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@
clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all