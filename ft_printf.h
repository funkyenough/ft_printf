#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

void	ft_putchar(int c);
void	ft_putstr(const char *str);
void	ft_putnbr(int nb);
void	ft_putunbr(unsigned int nb);
void	ft_putptr(unsigned long long num);
void	ft_printptr(void *p);
void	ft_putnbr_hex(int nbr, int is_upper);

#endif