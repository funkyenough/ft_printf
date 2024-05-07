#include "./libft/libft.h"
#include "ft_printf.h"

static void	ft_putnbr_hex_recursion(long nbr, char *str, int digits)
{
	if (nbr >= digits)
	{
		ft_putnbr_hex_recursion(nbr / digits, str, digits);
		ft_putnbr_hex_recursion(nbr % digits, str, digits);
	}
	else
		write(1, &str[nbr], 1);
}

static void	ft_putnbr_hex(int nbr, int is_upper)
{
	int				digits;
	unsigned int	unsigned_nbr;
	char			*base_upper;
	char			*base_lower;

	base_lower = "0123456789abcdef";
	base_upper = "0123456789ABCDEF";
	digits = 16;
	unsigned_nbr = (unsigned int)nbr;
	if (unsigned_nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (is_upper == 0)
		ft_putnbr_hex_recursion(unsigned_nbr, base_lower, digits);
	else
		ft_putnbr_hex_recursion(unsigned_nbr, base_upper, digits);
}

int	ft_printnbr_hex(int nbr, int is_upper)
{
	ft_putnbr_hex(nbr, is_upper);
}