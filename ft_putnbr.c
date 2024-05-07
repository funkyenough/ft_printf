#include "./libft/libft.h"
#include "ft_printf.h"

void	ft_putnbr(int n)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		write(1, "-", 1);
		nb *= -1;
	}
	if (nb >= 10)
		ft_putnbr(nb / 10);
	nb = nb % 10 + '0';
	write(1, &nb, 1);
}
