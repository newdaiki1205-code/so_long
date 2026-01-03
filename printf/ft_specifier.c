/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_specifier.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:23:49 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/03 23:14:30 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_specifier(char a, va_list args)
{
	int	res;

	res = 0;
	if (a == 'c')
		res = print_char(va_arg(args, int));
	else if (a == 's')
		res = print_str(va_arg(args, char *));
	else if (a == 'p')
		res = print_pointer((unsigned long)va_arg(args, void *), 1, a);
	else if (a == 'd' || a == 'i')
		res = print_decimal(va_arg(args, int), 1);
	else if (a == 'u')
		res = print_ud((unsigned int)va_arg(args, unsigned int), 1);
	else if (a == 'x' || a == 'X')
		res = print_hex((unsigned int)va_arg(args, unsigned int), 1, a);
	else if (a == '%')
		res = print_percent();
	else
		res = print_others(a);
	return (res);
}

int	print_percent(void)
{
	write(1, "%", 1);
	return (1);
}

int	print_others(char a)
{
	write(1, "%", 1);
	write(1, &a, 1);
	return (2);
}

int	print_pointer(unsigned long n, int len, char a)
{
	if (!n)
	{
		ft_putstr_fd("(nil)", 1);
		return (5);
	}
	write(1, "0x", 2);
	len = ft_putnbr_pointer(n, len, a);
	return (len + 2);
}
