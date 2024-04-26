#include "ft_printf.h"
#include "./libft/libft.h"

static void	ft_putnbr_recursion(long nbr, char *str, int digits)
{
	if (nbr >= digits)
	{
		ft_putnbr_recursion(nbr / digits, str, digits);
		ft_putnbr_recursion(nbr % digits, str, digits);
	}
	else
		write(1, &str[nbr], 1);
}

void	ft_putnbr_base(int nbr)
{
	int digits;
	long unsigned_nbr;
	char *base;
	
	base = "0123456789abcdef";

	digits = ft_strlen(base);
	unsigned_nbr = (unsigned int)nbr;
	if (unsigned_nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (unsigned_nbr < 0)
	{
		write(1, &"-", 1);
		unsigned_nbr = -unsigned_nbr;
	}
	ft_putnbr_recursion(unsigned_nbr, base, digits);
}