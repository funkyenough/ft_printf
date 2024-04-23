NAME = ft_printf
SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putptr.c ft_printptr.c ft_printf.c
OBJS = $(SRC:.c=.o)
AR = ar rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME) : $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

archive : $(OBJS)
	$(AR) $(NAME) $(OBJS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all