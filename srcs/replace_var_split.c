/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:27:54 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 16:07:25 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_variable_value(char *str, t_env *env)
{
	char	*value;
	char	*name;

	name = isolate_var_name(str);
	if (!name)
		return (NULL);
	value = get_env_value(name, env);
	free(name);
	return (value);
}

static char	*replace_name(char *str, t_env *env)
{
	char	*value;
	int		i;

	value = get_variable_value(str, env);
	if (!value)
		return (NULL);
	return (str);
}

char	*replace_var_split(char *str, t_env *env)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1]
				&& str[i + 1] != ' ')
		{
			str = replace_name(str, env);
			if (!str)
				return (NULL);
		}
		i++;
	}
	return (str);
}
