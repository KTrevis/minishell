/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:10:04 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/08 16:00:39 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_split_split(char ***split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free_split(split[i]);
		i++;
	}
	free(split);
}

int	exec(char ***split)
{
	if (!split)
		return (EXIT);
	for (int i = 0; split[i]; i++) {
		for (int j = 0; split[i][j]; j++)
			printf("%s\n", split[i][j]);
		printf("\n");
	}
	free_split_split(split);
	return (SUCCESS);
}
