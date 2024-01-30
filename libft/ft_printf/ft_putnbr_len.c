/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:08:06 by ketrevis          #+#    #+#             */
/*   Updated: 2023/11/01 10:59:51 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	ft_putnbr_len(int n, unsigned int *len)
{
	if (n == -2147483648)
	{
		return (ft_putstr_len("-2147483648"));
	}
	if (n < 0)
	{
		n = -n;
		*len += ft_putchar_len('-');
	}
	if (n >= 10)
		ft_putnbr_len(n / 10, len);
	*len += ft_putchar_len(n % 10 + 48);
	return (*len);
}

int	ft_putnbr_unsigned_len(unsigned int n)
{
	static int	len;

	len = 0;
	if (n >= 10)
		ft_putnbr_unsigned_len(n / 10);
	len += ft_putchar_len(n % 10 + 48);
	return (len);
}
