/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:48:59 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 16:46:38 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	builtin(t_split *split, t_env *env)
{
	if (!ft_strcmp(split->str, "echo"))
		return (ft_echo(split->next), 1);
	if (!ft_strcmp(split->str, "env"))
		return (display_env(env), 1);
	return (0);
}

int	parse_input(char *input, t_env *env)
{
	t_split	*split;

	split = shell_split(input, env);
	if (!split)
		return (0);
	if (builtin(split, env))
		return (free_shell_split(split), 1);
	free_shell_split(split);
	return (1);
}
