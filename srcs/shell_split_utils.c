/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 13:53:50 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 13:55:08 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_shell_split(t_list *head)
{
	t_list	*tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp->content);
		free(tmp);
	}
}
