/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:07:31 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/06 18:57:48 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_env_list(t_env *env_list)
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

void	display_env(t_env *env)
{
	while (env)
	{
		printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
}

char	*get_var_value(t_env *head, char *name)
{
	while (head)
	{
		if (!ft_strcmp(head->name, name))
			return (head->value);
		head = head->next;
	}
	return ("");
}

t_env	*add_env_node(t_env *head, char *name, char *value)
{
	t_env	*new;
	t_env	*curr;

	curr = head;
	if (!name || !value)
		return (free(name), free(value), free_env_list(head), NULL);
	new = ft_calloc(1, sizeof(t_env));
	if (!new)
		return (free(name), free(value), free_env_list(head), NULL);
	new->name = name;
	new->value = value;
	if (!head)
		head = new;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	return (head);
}
