/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/09 10:31:10 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/09 10:51:20 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main(void)
{
	int		myret;
	int		ogret;
	char	str[] = "Hello, World";
	char	nullstr[] = "";

	// if (__STDC_VERSION__ >= 201710L)
	// 	printf("We are using C18!\n");
	// else if (__STDC_VERSION__ >= 201112L)
	// 	printf("We are using C11!\n");
	// else if (__STDC_VERSION__ >= 199901L)
	// 	printf("We are using C99!\n");
	// else
	// 	printf("We are using C89/C90!\n");
	myret = ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o',
			' ', 'W', 'o', 'r', 'l', 'd', '!', '\0');
	printf("%d\n", myret);
	ogret = printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o', ' ',
			'W', 'o', 'r', 'l', 'd', '!', '\0');
	printf("%d\n", ogret);
	myret = ft_printf("%s\n", "Hello, World!");
	printf("%d\n", myret);
	ogret = printf("%s\n", "Hello, World!");
	printf("%d\n", ogret);
	myret = ft_printf("%s\n", nullstr);
	printf("%d\n", myret);
	ogret = printf("%s\n", nullstr);
	printf("%d\n", ogret);
	myret = ft_printf("%d\n", 12345678);
	printf("%d\n", myret);
	ogret = printf("%d\n", 12345678);
	printf("%d\n", ogret);
	ft_printf("%p\n", str);
	ft_printf("%u\n", 4294967295);
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
