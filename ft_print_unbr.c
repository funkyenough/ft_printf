/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_unbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:29:59 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/07 14:56:13 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nbr_len(int i);
void	ft_put_unbr(unsigned int nb);
void	ft_putunbr_recursion(unsigned int nb);

int	ft_print_unbr(unsigned int n)
{
	ft_put_unbr(n);
	return (ft_nbr_len(n));
}

void	ft_put_unbr(unsigned int nb)
{
	if (nb == 0)
	{
		write(1, "0", 1);
		return ;
	}
	ft_putunbr_recursion(nb);
}

void	ft_putunbr_recursion(unsigned int nb)
{
	char	mod;

	if (nb != 0)
	{
		mod = nb % 10 + '0';
		ft_putunbr_recursion(nb / 10);
		write(1, &mod, 1);
	}
}
