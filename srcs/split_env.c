/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:13:53 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 10:38:42 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static char	*get_variable_name(char *env)
{
	uint	i;
	char	*name;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	name = ft_calloc(i + 1, sizeof(char));
	if (!name)
		return (NULL);
	i = 0;
	while (env[i] && env[i] != '=')
	{
		name[i] = env[i];
		i++;
	}
	return (name);
}

static char	*get_variable_value(char *env)
{
	uint	i;
	char	*value;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	value = ft_strdup(env + i);
	return (value);
}

t_env	*split_env(char **env)
{
	t_env	*env_list;
	uint	i;

	i = 0;
	env_list = NULL;
	while (env[i])
	{
		env_list = add_node(get_variable_name(env[i]),
			get_variable_value(env[i]), env_list);
		if (!env_list)
			return (free_list(env_list), NULL);
		i++;
	}
	return (env_list);
}
