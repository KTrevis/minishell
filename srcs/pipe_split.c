/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:53 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/07 18:53:26 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_split	*pipe_split(char *input)
{
	int		i;
	t_split	*split;
	char	quote;

	i = 0;
	quote = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			if (input[i] == quote)
				quote = 0;
			else if (!quote)
				quote = input[i];
		}
		i++;
	}
	return (split);
}
