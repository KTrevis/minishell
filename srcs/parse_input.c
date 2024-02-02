/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:13:01 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/02 13:35:42 by ketrevis         ###   ########.fr       */
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

static char	quote_not_closed(char *str)
{
	int		i;
	char	quote;

	i = 0;
	quote = 0;
	while (str[i])
	{
		if ((!quote || quote == str[i]) && (str[i] == '\'' || str[i] == '"'))
		{
			if (!quote)
				quote = str[i];
			else
				quote = 0;
		}
		i++;
	}
	return (quote);
}

int	parse_input(char *input, t_env *env)
{
	t_split	*split;

	printf("%c\n", quote_not_closed(input));
	input = replace_every_var_names(input, env);
	if (!input)
		return (0);
	split = shell_split(input);
	free_shell_split(split);
	free(input);
	return (1);
}
