/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:30:06 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/09 10:16:07 by yinhong          ###   ########.fr       */
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
			print_len += ft_format(args, *(str++));
		}
		else
			print_len += ft_print_char(*(const char *)str);
		str++;
	}
	va_end(args);
	return (print_len);
}

#include <stdio.h>

int	main(void)
{
	 if (__STDC_VERSION__ >= 201710L)
        printf("We are using C18!\n");
    else if (__STDC_VERSION__ >= 201112L)
        printf("We are using C11!\n");
    else if (__STDC_VERSION__ >= 199901L)
        printf("We are using C99!\n");
    else
        printf("We are using C89/C90!\n");
	// char str[] = "Hello, World";
	int myret;
	int ogret;

	ft_printf("%c%c%c\n", 'H', 'e', 'l');
	myret = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o', ' ',
	'W', 'o', 'r', 'l', 'd', '!', '\0');
	printf("%d\n", myret);
	ogret = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o', ' ',
	'W', 'o', 'r', 'l', 'd', '!', '\0');
	printf("%d\n", ogret);

	// myret = ft_printf("%s\n", "Hello, World!");
	// printf("%d\n", myret);
	// ogret = printf("%s\n", "Hello, World!");
	// printf("%d\n", ogret);

	// myret = ft_printf("%d\n", 12345678);
	// printf("%d\n", myret);
	// ogret = printf("%d\n", 12345678);
	// printf("%d\n", ogret);


	// ft_printf("%p\n", str);
	// ft_printf("%u\n", 4294967295);
	// ft_printf("%x\n", -12345);
	// printf("%x\n", -12345);
	// ft_printf("%x\n", 123450000);
	// printf("%x\n", 123450000);
	// ft_printf("%X\n", -12345);
	// printf("%X\n", -12345);
	// ft_printf("%X\n", 123450000);
	// printf("%X\n", 123450000);
	return (0);
}
