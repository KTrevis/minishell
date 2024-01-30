/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:31:50 by ketrevis          #+#    #+#             */
/*   Updated: 2024/01/30 18:09:51 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtin(char **split, char *input)
{
	if (!ft_strcmp(split[0], "echo"))
		return (ft_echo(input), 1);
	return (0);
}

void	parse_input(char *input)
{
	char	**split;

	split = ft_split(input, ' ');
	if (builtin(split, input))
		return ;
	free_split(split);
}
