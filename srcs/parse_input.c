/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:13:01 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/02 11:48:20 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*replace_every_var_names(char *input, t_env *env)
{
	char	*replaced;
	char	*old;

	old = input;
	replaced = replace_var_names(input, env);
	if (!replaced)
		return (NULL);
	while (ft_strcmp(old, replaced))
	{
		if (old != input)
			free(old);
		old = replaced;
		replaced = replace_var_names(old, env);
		if (!replaced)
			return (free(input), free(old), NULL);
	}
	if (old != input)
		free(old);
	free(input);
	return (replaced);
}

int	parse_input(char *input, t_env *env)
{
	t_split	*split;

	input = replace_every_var_names(input, env);
	if (!input)
		return (0);
	split = shell_split(input);
	free_shell_split(split);
	free(input);
	return (1);
}
