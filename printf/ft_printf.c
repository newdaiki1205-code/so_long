/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 15:51:12 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/03 23:11:56 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printf(const char *format, ...)
{
	int		i;
	int		re;
	va_list	args;

	if (!format)
		return (-1);
	i = 0;
	re = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%' && (format[++i]))
			re += ft_specifier(format[i], args);
		else
		{
			write(1, &format[i], 1);
			re++;
		}
		i++;
	}
	va_end(args);
	return (re);
}

// #include <stdio.h>
// #include <limits.h>

// int	main(void)
// {
// 	char c = 'c';
// 	char *test = "HI";
// 	int n = -9;
// 	char *p = NULL;
// 	unsigned int ui = UINT_MAX;
// 	int i = printf("Test: %d %% %c %p %x %s\n", n, c, p, ui, test);
// 	int j = ft_printf("Test: %d %% %c %p %x %s\n", n, c, p, ui, test);
// 	printf("%i\n", i);
// 	printf("%i\n", j);
// 	return (0);
// }