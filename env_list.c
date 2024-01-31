/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 11:41:02 by ketrevis          #+#    #+#             */
/*   Updated: 2024/01/31 13:25:31 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*get_last_element(t_env *head)
{
	while (head->next)
		head = head->next;
	return (head);
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
		get_last_element(head)->next = new;
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

void	display_env(t_env *env_list)
{
	t_env	*curr;

	curr = env_list;
	while (curr)
	{
		printf("%s=%s\n", curr->name, curr->value);
		curr = curr->next;
	}
}
