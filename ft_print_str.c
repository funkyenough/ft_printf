/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_str.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yinhong <yinhong@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/23 15:35:25 by yinhong           #+#    #+#             */
/*   Updated: 2024/09/15 16:05:23 by yinhong          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_str(int fd, const char *str)
{
	const char	*ptr;

	if (str == NULL)
	{
		write(fd, "(null)", 6);
		return (6);
	}
	ptr = str;
	while (*ptr)
		write(fd, ptr++, 1);
	return (ft_strlen(str));
}
