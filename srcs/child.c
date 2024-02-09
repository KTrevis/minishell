/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   child.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 13:48:44 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/09 14:27:28 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static char	**remove_surrounding_quotes(char **split)
{
	char	**no_surr_quote;
	int		i;

	no_surr_quote = ft_calloc(split_size(split) + 1, sizeof(char *));
	if (!no_surr_quote)
		return (NULL);
	i = 0;
	while (split[i])
	{
		if (split[i][0] == '"' || split[i][0] == '\'')
			no_surr_quote[i] = ft_substr(split[i], 1, ft_strlen(split[i]) - 2);
		else
			no_surr_quote[i] = ft_strdup(split[i]);
		i++;
	}
	return (no_surr_quote);
}

void	run_command(char **split, char **env)
{
	char	**no_surr_quotes;

	(void)split;
	(void)env;
	no_surr_quotes = remove_surrounding_quotes(split);
	free_split(no_surr_quotes);
}
