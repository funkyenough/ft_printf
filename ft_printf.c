/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:30:06 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/09 13:29:51 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(va_list args, int format)
{
	int	print_len;

	print_len = 0;
	if (format == '%')
		print_len += ft_print_char('%');
	else if (format == 'c')
		print_len += ft_print_char(va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_str(va_arg(args, void *));
	else if (format == 'p')
		print_len += ft_print_ptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_unbr(va_arg(args, unsigned int));
	else if (format == 'x')
		print_len += ft_print_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		print_len += ft_print_hex(va_arg(args, unsigned int), 1);
	return (print_len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		print_len;

	print_len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			print_len += ft_format(args, *str);
		}
		else
			print_len += ft_print_char(*(const char *)str);
		str++;
	}
	va_end(args);
	return (print_len);
}
