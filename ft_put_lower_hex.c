#include "ft_printf.h"

#define HEXLEN 8

void	ft_mod_sixteen(int i)
{
	if (i >= 16)
		ft_mod_sixteen(i / 16);
	if (i % 16 < 10)
		ft_putchar((i % 16) + '0');
	else
		ft_putchar((i % 16) + 'a');
}

void	ft_put_lower_hex(int i)
{
	if (i == 0)
		ft_putchar('0');
	else
		ft_mod_sixteen((unsigned int)i);
}