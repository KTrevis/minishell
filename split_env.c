/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 18:13:53 by ketrevis          #+#    #+#             */
/*   Updated: 2024/01/30 20:06:38 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

char	*get_variable_name(char *env)
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

char	*get_variable_value(char *env)
{
	uint	i;
	uint	j;
	char	*value;

	i = 0;
	while (env[i] && env[i] != '=')
		i++;
	i++;
	j = i;
	while (env[j])
		j++;
	value = ft_calloc(j - i + 1, sizeof(char));
	j = 0;
	while (env[i])
		value[j++] = env[i++];
	return (value);
}

t_env	*add_node(char *name, char *value, t_env *head)
{
	t_env	*new;

	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	if (!name || !value)
		return (free(new), free(name), free(value), NULL);
	if (!head)
		head = new;
	else
		head->next = new;
	new->name = name;
	new->value = value;
	return (head);
}

void	free_list(t_env *env_list)
{
	t_env	*tmp;

	while (env_list)
	{
		tmp = env_list;
		env_list = env_list->next;
		free(tmp->name);
		free(tmp->value);
		free(tmp);
	}
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
