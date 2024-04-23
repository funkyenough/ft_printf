#include "ft_printf.h"
#include <stdio.h>

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_putchar(int c)
{
	write(1, &c, 1);
}

// void	ft_putstr(char *str)
// {
// 	while (*str)
// 	{
// 		write(1, str, 1);
// 		str++;
// 	}
// }
void	ft_printf(const char *str, ...)
{
	va_list	args;

	va_start(args, str);
	while (*str)
	{
		while (*str != '%' && *str)
		{
			write(1, str, 1);
			str++;
		}
		if (*str++ == '%')
		{

			if (*str == 'c')
			{
				ft_putchar(va_arg(args, int));
				str++;
			}
			else if (*str == 's')
			{
				ft_putstr(va_arg(args, void *));
				str++;
			}
			else if (*str == 'd')
			{
				ft_putnbr(va_arg(args, int));
				str++;
			}
			else
				str++;
		}
	}
	va_end(args);
}

int	main(void)
{
	// ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c", 'H', 'e', 'l', 'l', 'o', ' ',
	// 	'W', 'o', 'r', 'l', 'd', '!', '\0');
	// ft_printf("%s\n", "Hello, World!");
	// ft_printf("%d", 12345678);
	return (0);
}