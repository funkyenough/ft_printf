/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:30:06 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/07 15:23:32 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(va_list args, int format)
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
		ft_print_nbr(va_arg(args, int));
	else if (format == 'u')
		ft_print_unbr(va_arg(args, unsigned int));
	else if (format == 'x')
		ft_print_hex(va_arg(args, unsigned int), 0);
	else if (format == 'X')
		ft_print_hex(va_arg(args, unsigned int), 1);
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
		while (*str != '%' && *str)
		{
			write(1, str++, 1);
			print_len++;
		}
		if (*str == '%')
		{
			ft_format(args, *(str + 1));
			str += 2;
		}
	}
	va_end(args);
	return (print_len);
}

#include <stdio.h>

int	main(void)
{
	// char str[] = "Hello, World";
	// ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o', ' ',
	// 'W', 'o', 'r', 'l', 'd', '!', '\0');
	// ft_printf("%s\n", "Hello, World!");
	// ft_printf("%d\n", 12345678);
	// ft_printf("%p\n", str);
	// ft_printf("%u\n", 4294967295);
	ft_printf("%x\n", -12345);
	printf("%x\n", -12345);
	ft_printf("%x\n", 123450000);
	printf("%x\n", 123450000);
	ft_printf("%X\n", -12345);
	printf("%X\n", -12345);
	ft_printf("%X\n", 123450000);
	printf("%X\n", 123450000);
	return (0);
}
