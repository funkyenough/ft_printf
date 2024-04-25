#include "ft_printf.h"

static int	ft_check_base(char *str)
{
	int	i;
	int	j;
	int	len;

	i = 0;
	j = 0;
	len = ft_str_len(str);
	if (len <= 1)
		return (0);
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

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

void	ft_putnbr_base(int nbr, char *base)
{
	int digits;
	long long_nbr;

	if (ft_check_base(base) == 0)
		return ;
	digits = ft_strlen(base);
	long_nbr = (long)nbr;
	if (long_nbr == 0)
	{
		write(1, "0", 1);
		return ;
	}
	else if (long_nbr < 0)
	{
		write(1, &"-", 1);
		long_nbr = -long_nbr;
	}
	ft_putnbr_recursion(long_nbr, base, digits);
}