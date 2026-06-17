/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:28:42 by luvieira          #+#    #+#             */
/*   Updated: 2026/06/16 21:58:41 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putlongnbr(unsigned long l, int *i)
{
	char	*decimal;

	decimal = "0123456789abcdef";

	if (l >= 16)
		ft_putlongnbr(l / 16, i);
	ft_putchar_fd(decimal[l % 16], 1);
	(*i)++;
}

static void	ft_putnbr(long l, int *i, char c)
{
	int		d;
	char	*decimal;

	d = 10;
	decimal = "0123456789";
	if (l < 0)
	{
		l = -l;
		ft_putchar_fd('-', 1);
		*i++;
	}
	if (c == 'x' || c == 'X')
	{
		d = 16;
		if (c == 'X')
			decimal = "0123456789ABCDEF";
		else
			decimal = "0123456789abcdef";
	}
	if (l >= d)
		ft_putnbr(l / d, i, c);
	ft_putchar_fd(decimal[l % d], 1);
	(*i)++;
}

static int	ft_putstr(char *str)
{
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

static int	getarg(char c, va_list args)
{
	char	*str;
	int		i;

	i = 0;
	if (c == 'c' || c == '%')
	{
		if (c == 'c')
			ft_putchar_fd((char)va_arg(args, int), 1);
		else
			ft_putchar_fd(c, 1);
		return (1);
	}
	if (c == 's')
		return (ft_putstr(va_arg(args, char *)));
	if (c == 'p')
	{
		str = "0x";
		i += ft_putstr(str);
		ft_putlongnbr((unsigned long)va_arg(args, void *), &i);
	}
	if (c == 'd' || c == 'i')
		ft_putnbr((long)va_arg(args, int), &i, c);
	if (c == 'u' || c == 'x' || c == 'X')
		ft_putnbr((long)va_arg(args, unsigned int), &i, c);
	return (i);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	const char	*convertable;

	convertable = "cspdiuxX%";
	i = 0;
	va_start(args, format);
	while (*format)
	{
		if (format[0] == '%' && ft_strchr(convertable, format[1]))
		{
			i += getarg(format[1], args);
			format += 2;
		}
		else
		{
			ft_putchar_fd(format[0], 1);
			i++;
			format++;
		}
	}
	va_end(args);
	return (i);
}
