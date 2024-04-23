#include "ft_printf.h"
#include <stdio.h>

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
		if (*str == '%')
		{
			if (*(str + 1) == 'c')
				ft_putchar(va_arg(args, int));
			else if (*(str + 1) == 's')
				ft_putstr(va_arg(args, void *));
			else if (*(str + 1) == 'p')
				ft_printptr(va_arg(args, void *));
			// else if (*(str + 1) == 'd')
			else if (*(str + 1) == 'd' || *(str + 1) == 'i')
				ft_putnbr(va_arg(args, int));
			else if (*(str + 1) == 'u')
				ft_putunbr(va_arg(args, unsigned int));
			str += 2;
		}
	}
	va_end(args);
}

int	main(void)
{
	char str[] = "Hello, World";
	ft_printf("%c%c%c%c%c%c%c%c%c%c%c%c%c\n", 'H', 'e', 'l', 'l', 'o', ' ', 'W',
		'o', 'r', 'l', 'd', '!', '\0');
	ft_printf("%s\n", "Hello, World!");
	ft_printf("%d\n", 12345678);
	ft_printf("%p\n", str);
	ft_printf("%u\n", 1234567896666666012);
	printf("%u\n", 1234567896666);
	return (0);
}