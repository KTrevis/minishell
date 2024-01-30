/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_len.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:07:13 by ketrevis          #+#    #+#             */
/*   Updated: 2023/11/01 10:37:13 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr_len(char *str)
{
	int	i;

	if (!str)
		return (ft_putstr_len("(null)"));
	i = 0;
	while (str[i])
		ft_putchar_len(str[i++]);
	return (i);
}
