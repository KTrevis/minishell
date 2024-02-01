/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 14:08:11 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 14:20:39 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static int	is_only_n(char *str)
{
	int	i;

	i = 1;
	while (str[i])
	{
		if (str[i] != 'n')
			return (0);
		i++;
	}
	return (1);
}

void	ft_echo(t_split *split)
{
	bool	flag;

	flag = false;
	while (split && split->str[0] == '-' && is_only_n(split->str + 1))
	{
		flag = true;
		split = split->next;
	}
	while (split)
	{
		write(1, split->str, ft_strlen(split->str));
		if (split->next)
			ft_putchar_fd(' ', 1);
		split = split->next;
	}
	if (!flag)
		ft_putchar_fd('\n', 1);
}
