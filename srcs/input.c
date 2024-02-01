/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:31:50 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 11:04:25 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(char **split, char *input, t_env *env_list)
{
	(void)input;
	if (!ft_strcmp(split[0], "echo"))
		return (ft_echo(split), 1);
	if (!ft_strcmp(split[0], "env"))
		return (display_env(env_list), 1);
	return (0);
}

int	parse_input(char *input, t_env *env_list)
{
	char	**split;

	split = quote_split(input);
	if (!split)
		return (0);
	if (!split[0])
		return (free_split(split), 1);
	if (builtin(split, input, env_list))
		return (free_split(split), 1);
	printf("%s: command not found\n", split[0]);
	free_split(split);
	return (1);
}
