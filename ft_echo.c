/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:36:04 by ketrevis          #+#    #+#             */
/*   Updated: 2024/01/31 14:29:50 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	normal_print(char *str, t_env *env_list)
{
	bool	quote;
	(void)env_list;

	quote = false;
	if (str[0] == '"')
	{
		quote = true;
		str++;
	}
	if (quote)
		write(1, str, ft_strlen(str) - 1);
	else
		write(1, str, ft_strlen(str));
}

void	ft_echo(char **split, t_env *env_list)
{
	uint	i;
	bool	flag;

	(void)env_list;
	flag = false;
	i = 1;
	while (split[i])
	{
		if (split[i][0] == '\'')
			write(1, split[i] + 1, ft_strlen(split[i]) - 2);
		else
			normal_print(split[i], env_list);
		write(1, " ", 1);
		i++;
	}
	if (!flag)
		printf("\n");
}
