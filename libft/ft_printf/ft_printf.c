/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:05:45 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/13 14:43:16 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_format(char c, va_list args)
{
	unsigned int	arg;
	unsigned int	len;

	len = 0;
	if (c == 'c')
		return (ft_putchar_len(va_arg(args, int)));
	if (c == 's')
		return (ft_putstr_len(va_arg(args, char *)));
	if (c == 'i' || c == 'd')
		return (ft_putnbr_len(va_arg(args, int), &len));
	if (c == 'u')
		return (ft_putnbr_unsigned_len(va_arg(args, unsigned int)));
	if (c == 'x' || c == 'X')
	{
		arg = va_arg(args, unsigned int);
		if (arg == 0)
			return (ft_putchar_len('0'));
		else
			return (ft_puthexa_unsigned_len(arg, c));
	}
	if (c == 'p')
		return (ft_putaddr_len(va_arg(args, void *)));
	if (c == '%')
		return (ft_putchar_len('%'));
	return (1);
}

int	ft_printf(const char *str, ...)
{
	int			len;
	va_list		args;

	if (!str)
		return (-1);
	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			len += ft_format(*++str, args);
		else
			len += ft_putchar_len(*str);
		str++;
	}
	va_end(args);
	return (len);
}
