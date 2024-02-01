/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_env.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:15:16 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 13:10:10 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_last_env(t_env *curr)
{
	while (curr->next)
		curr = curr->next;
	return (curr);
}

t_env	*add_env_var(t_env *env_list, char *name, char *value)
{
	t_env	*new;

	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (NULL);
	if (!env_list)
		env_list = new;
	else
		get_last_env(env_list)->next = new;
	new->name = name;
	new->value = value;
	return (env_list);
}

static char	*get_env_value(char *var)
{
	char	*name;
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (var[i] && var[i] != '=')
		i++;
	name = ft_calloc(ft_strlen(var) - i + 1, sizeof(char));
	i++;
	while (var[i])
		name[j++] = var[i++];
	return (name);
}

static char	*get_env_name(char *var)
{
	char	*name;
	int	i;

	i = 0;
	while (var[i] && var[i] != '=')
		i++;
	name = ft_calloc(i + 1, sizeof(char));
	i = 0;
	while (var[i] && var[i] != '=')
	{
		name[i] = var[i];
		i++;
	}
	return (name);
}

t_env	*split_env(char **env)
{
	t_env	*env_list;
	int		i;

	env_list = NULL;
	i = 0;
	while (env[i])
	{
		env_list = add_env_var(env_list, get_env_name(env[i]), get_env_value(env[i]));
		i++;
	}
	return (env_list);
}
