/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:29:55 by yinhong           #+#    #+#             */
/*   Updated: 2024/09/15 16:19:31 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_hex_len(int nbr);
static void	ft_put_hex(int fd, int nbr, int is_upper);
static void	ft_put_hex_recursion(int fd, long nbr, char *str, int digits);

int	ft_print_hex(int fd, int nbr, int is_upper)
{
	ft_put_hex(fd, nbr, is_upper);
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

static void	ft_put_hex(int fd, int nbr, int is_upper)
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
		write(fd, "0", 1);
		return ;
	}
	else if (is_upper == 0)
		ft_put_hex_recursion(fd, unsigned_nbr, base_lower, digits);
	else
		ft_put_hex_recursion(fd, unsigned_nbr, base_upper, digits);
}

static void	ft_put_hex_recursion(int fd, long nbr, char *str, int digits)
{
	if (nbr >= digits)
	{
		ft_put_hex_recursion(fd, nbr / digits, str, digits);
		ft_put_hex_recursion(fd, nbr % digits, str, digits);
	}
	else
		write(fd, &str[nbr], 1);
}
