/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:43:59 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/03 23:14:43 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(char c)
{
	write(1, &c, 1);
	return (1);
}

int	print_str(char *s)
{
	if (!s)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	else
		ft_putstr_fd(s, 1);
	return (ft_strlen(s));
}

int	print_hex(unsigned int n, int len, char a)
{
	len = ft_putnbr_hex(n, len, a);
	return (len);
}

int	print_decimal(int n, int len)
{
	len = ft_putnbr_base10(n, 1, len);
	return (len);
}

int	print_ud(unsigned int n, int len)
{
	len = ft_putnbr_ud(n, 1, len);
	return (len);
}
