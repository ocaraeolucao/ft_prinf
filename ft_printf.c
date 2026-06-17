/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luvieira <luvieira@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/08 18:28:42 by luvieira          #+#    #+#             */
/*   Updated: 2026/06/17 19:29:12 by luvieira         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putlongnbr(unsigned long l, char *str, int *i)
{
	char			*decimal;

	if (!l)
		*i = ft_putstr("(nil)");
	else
	{
		if (str)
			*i = ft_putstr(str);
		str = NULL;
		decimal = "0123456789abcdef";
		if (l >= 16)
			ft_putlongnbr(l / 16, str, i);
		ft_putchar_fd(decimal[l % 16], 1);
		(*i)++;
	}
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
		(*i)++;
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
	int	i;

	i = 0;
	if (!str)
		return (ft_putstr("(null)"));
	while (str[i] != '\0')
	{
		ft_putchar_fd(str[i], 1);
		i++;
	}
	return (i);
}

static int	getarg(char c, va_list args)
{
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
		ft_putlongnbr((unsigned long)va_arg(args, void *), "0x", &i);
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
		if (*format == '%' && format[1] && ft_strchr(convertable, format[1]))
		{
			format++;
			i += getarg(*format, args);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			i++;
		}
		format++;
	}
	va_end(args);
	return (i);
}
