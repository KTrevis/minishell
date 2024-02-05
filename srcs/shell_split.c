/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:50:34 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/05 14:55:17 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_split	*add_string(t_split *head, char *str)
{
	t_split	*new;
	t_split	*curr;

	new = ft_calloc(1, sizeof(t_split));
	if (!new)
		return (NULL);
	new->str = str;
	if (!head)
		head = new;
	else
	{
		curr = head;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	return (head);
}

static char	*create_word(char *str, int *i)
{
	
}

static t_split	*new_linked_list(char *str)
{
	t_split	*split;
	int		i;

	split = NULL;
	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			split = add_string(split, create_word(str, &i));
		i++;
	}
	return (split);
}

t_split	**shell_split(char **old_split)
{
	int		i;
	t_split	**split;

	i = 0;
	split = ft_calloc(split_size(old_split) + 1, sizeof(t_split));
	if (!split)
		return (NULL);
	while (old_split[i])
	{
		split[i] = new_linked_list(old_split[i]);
		i++;
	}
	return (split);
}
