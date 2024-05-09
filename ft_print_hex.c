/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:29:55 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/09 11:24:00 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(int nbr);
static void	ft_put_hex(int nbr, int is_upper);
static void	ft_put_hex_recursion(long nbr, char *str, int digits);

int	ft_print_hex(int nbr, int is_upper)
{
	ft_put_hex(nbr, is_upper);
	return (ft_hex_len(nbr));
}

int	ft_hex_len(int nbr)
{
	unsigned int	unbr;
	int				len;

	len = 0;
	if (nbr == 0)
		return (1);
	unbr = (unsigned int)nbr;
	while (unbr != 0)
	{
		len++;
		unbr /= 16;
	}
	return (len);
}

static void	ft_put_hex(int nbr, int is_upper)
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
		ft_put_hex_recursion(unsigned_nbr, base_lower, digits);
	else
		ft_put_hex_recursion(unsigned_nbr, base_upper, digits);
}

static void	ft_put_hex_recursion(long nbr, char *str, int digits)
{
	if (nbr >= digits)
	{
		ft_put_hex_recursion(nbr / digits, str, digits);
		ft_put_hex_recursion(nbr % digits, str, digits);
	}
	else
		write(1, &str[nbr], 1);
}
