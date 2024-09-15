/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:30:06 by yinhong           #+#    #+#             */
/*   Updated: 2024/09/15 16:25:09 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_format(int fd, va_list args, int format)
{
	int	print_len;

	print_len = 0;
	if (format == '%')
		print_len += ft_print_char(fd, '%');
	else if (format == 'c')
		print_len += ft_print_char(fd, va_arg(args, int));
	else if (format == 's')
		print_len += ft_print_str(fd, va_arg(args, void *));
	else if (format == 'p')
		print_len += ft_print_ptr(fd, va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		print_len += ft_print_nbr(fd, va_arg(args, int));
	else if (format == 'u')
		print_len += ft_print_unbr(fd, va_arg(args, unsigned int));
	else if (format == 'x')
		print_len += ft_print_hex(fd, va_arg(args, unsigned int), 0);
	else if (format == 'X')
		print_len += ft_print_hex(fd, va_arg(args, unsigned int), 1);
	return (print_len);
}

int	ft_printf(int fd, const char *str, ...)
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
			print_len += ft_format(fd, args, *str);
		}
		else
			print_len += ft_print_char(fd, *(const char *)str);
		str++;
	}
	va_end(args);
	return (print_len);
}
