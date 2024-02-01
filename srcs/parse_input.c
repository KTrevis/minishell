/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:48:59 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 14:09:35 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(t_split *split)
{
	if (!ft_strcmp(split->str, "echo"))
		return (ft_echo(split->next), 1);
	return (0);
}

int	parse_input(char *input, t_env *env)
{
	t_split	*split;

	split = shell_split(input, env);
	if (builtin(split))
		return (free_shell_split(split), 1);
	free_shell_split(split);
	return (1);
}
