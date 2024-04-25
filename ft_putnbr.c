#include "./libft/libft.h"
#include "ft_printf.h"

void	ft_putnbr_recursion(int nb)
{
	char	mod;

	if (nb != 0)
	{
		mod = nb % 10 + '0';
		ft_putnbr_recursion(nb / 10);
		write(1, &mod, 1);
	}
}

void	ft_putnbr(int nb)
{
	if (nb == INT_MIN)
	{
		write(1, "-2147483648", 11);
		return ;
	}
	if (nb < 0)
	{
		write(1, &"-", 1);
		nb = -nb;
	}
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_putnbr_recursion(nb);
}
