/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:09:43 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/08 16:01:30 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static bool	is_empty(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'
			&& str[i] != '\v' && str[i] != '\f' && str[i] != '\r')
			return (false);
		i++;
	}
	return (true);
}

int	parse_input(char *input, t_env *env)
{
	char	**split;

	if (is_empty(input))
		return (free(input), EMPTY_INPUT);
	input = replace_var_names(input, env);
	if (!input)
		return (EXIT);
	split = pipe_split(input);
	if (exec(split_split(split)) == EXIT)
		return (free(input), free_split(split), EXIT);
	free_split(split);
	free(input);
	return (SUCCESS);
}
