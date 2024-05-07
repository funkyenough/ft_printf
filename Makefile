NAME = libftprintf.a
EXEC = ft_printf
SRC = ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c ft_putptr.c ft_printptr.c ft_printf.c ft_putnbr_hex.c ft_putnbr.c
OBJS = $(SRC:.c=.o)
AR = ar
ARFLAGS = rcs
RM = rm -f
CC = cc
CFLAGS = -Wall -Werror -Wextra
LIBFT_PATH = ./libft
LIBFT = libft.a

all : $(NAME)

$(NAME) : $(OBJS)
	make bonus -C $(LIBFT_PATH)
	cp $(LIBFT_PATH)/$(LIBFT) .
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

exec : $(OBJS)
	$(CC) $(CFLAGS) -o $(EXEC) $(OBJS) $(LIBFT)

$(LIBFT) :
	make -C $(LIBFT_PATH)/$(LIBFT) all

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME) $(EXEC) $(LIBFT)

re: fclean all