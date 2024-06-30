/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 13:29:53 by yinhong           #+#    #+#             */
/*   Updated: 2024/05/09 11:19:27 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define PREFIX_LENGTH 2
# define HEX_LENGTH 12

# include <stdarg.h>
# include <unistd.h>
# include <stdint.h>

int		ft_printf(const char *str, ...);
int		ft_print_char(const char c);
int		ft_print_hex(int nbr, int is_upper);
int		ft_print_nbr(int n);
int		ft_print_ptr(void *p);
int		ft_print_str(const char *str);
int		ft_print_unbr(unsigned int n);

void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);

#endif