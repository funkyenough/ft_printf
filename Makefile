NAME = libftprintf.a
EXEC = ft_printf
SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c ft_putptr.c ft_printptr.c ft_printf.c ft_put_lower_hex.c
OBJS = $(SRC:.c=.o)
AR = ar
ARFLAGS = rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = ./libft
LIBFT = $(LIBFT_PATH)/libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	make bonus -C $(LIBFT_PATH)
	cp $(LIBFT) .
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

exec : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS)

$(LIBFT) :
	make -C $(LIBFT_PATH) all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXEC)

re: fclean all