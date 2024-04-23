#include "ft_printf.h"

void	ft_putnbr_recursion(unsigned int nb)
{
	char	mod;

	if (nb != 0)
	{
		mod = nb % 10 + '0';
		ft_putnbr_recursion(nb / 10);
		write(1, &mod, 1);
	}
}

void	ft_putunbr(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_putnbr_recursion(nb);
}