/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:36:04 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 10:23:07 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_only_n(char *str)
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

void	ft_echo(char **split)
{
	uint	i;
	bool	flag;

	flag = false;
	i = 1;
	while (split[i] && !ft_strncmp(split[i], "-n", 2) && is_only_n(split[i]))
	{
		flag = true;
		i++;
	}
	while (split[i])
	{
		write(1, split[i], ft_strlen(split[i]));
		i++;
	}
	if (!flag)
		printf("\n");
}
