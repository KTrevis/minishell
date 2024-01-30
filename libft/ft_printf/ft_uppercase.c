/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uppercase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:07:01 by ketrevis          #+#    #+#             */
/*   Updated: 2023/12/13 14:18:49 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_uppercase_char(char c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

char	*ft_uppercase_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		str[i] = ft_uppercase_char(str[i]);
		i++;
	}
	return (str);
}
