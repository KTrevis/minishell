/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:34:41 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/07 18:35:19 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_list(t_split *head)
{
	t_split	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->str);
		free(tmp);
	}
}

t_split	*add_string(t_split *head, char *str)
{
	t_split	*new;
	t_split	*curr;

	new = ft_calloc(1, sizeof(t_split));
	if (!new)
		return (free_list(head), NULL);
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
