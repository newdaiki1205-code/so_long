/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dshirais <dshirais@student.42vienna.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/17 16:21:14 by dshirais          #+#    #+#             */
/*   Updated: 2026/01/05 16:49:02 by dshirais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
int		ft_specifier(char a, va_list args);
int		print_char(char c);
int		print_str(char *s);
int		print_hex(unsigned int n, int len, char a);
int		ft_putnbr_hex(unsigned int n, int len, char a);
int		print_decimal(int n, int len);
int		ft_putnbr_base10(int n, int fd, int len);
int		print_ud(unsigned int n, int len);
int		ft_putnbr_ud(unsigned int n, int fd, int len);
int		print_percent(void);
int		ft_putnbr_pointer(unsigned long n, int len, char a);
int		print_pointer(unsigned long n, int len, char a);
int		print_others(char a);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *s);

#endif