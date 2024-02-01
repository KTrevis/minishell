/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:48:59 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 13:52:16 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_input(char *input, t_env *env)
{
	t_list	*split;

	split = shell_split(input, env);
	for (t_list *curr = split; curr; curr = curr->next)
		printf("%s\n", (char *)curr->content);
	return (1);
}
