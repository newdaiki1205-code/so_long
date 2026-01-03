/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 18:30:46 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/03 23:22:01 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_pointer(unsigned long n, int len, char a)
{
	char			*base_low;
	unsigned long	num;
	unsigned long	res;

	base_low = "0123456789abcdef";
	num = n / 16;
	if (num > 0)
		len = ft_putnbr_pointer(num, len + 1, a);
	res = n % 16;
	write(1, &base_low[res], 1);
	return (len);
}

int	ft_putnbr_hex(unsigned int n, int len, char a)
{
	char			*base_low;
	char			*base_up;
	unsigned long	num;
	unsigned long	res;

	base_low = "0123456789abcdef";
	base_up = "0123456789ABCDEF";
	num = n / 16;
	if (num > 0)
		len = ft_putnbr_hex(num, len + 1, a);
	res = n % 16;
	if (a == 'x')
		write(1, &base_low[res], 1);
	if (a == 'X')
		write(1, &base_up[res], 1);
	return (len);
}

int	ft_putnbr_base10(int n, int fd, int len)
{
	char	res;
	int		num;

	if (n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n = -n;
		len++;
	}
	num = n / 10;
	if (num > 0)
		len = ft_putnbr_base10(num, fd, len + 1);
	res = n % 10 + '0';
	write(fd, &res, 1);
	return (len);
}

int	ft_putnbr_ud(unsigned int n, int fd, int len)
{
	char	res;
	int		num;

	num = n / 10;
	if (num > 0)
		len = ft_putnbr_base10(num, fd, len + 1);
	res = n % 10 + '0';
	write(fd, &res, 1);
	return (len);
}
