/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:50:34 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/07 18:34:49 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*create_word(char *str, int *i)
{
	(void)str;
	(void)i;
	return (NULL);
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
		{
			split = add_string(split, create_word(str, &i));
			if (!split)
				return (NULL);
		}
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
		if (!split[i])
			return (free(split), NULL);
		i++;
	}
	return (split);
}
