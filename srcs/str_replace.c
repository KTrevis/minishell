/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:32:02 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/02 11:10:15 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static size_t	get_new_str_size(char *str, char *old, char *new)
{
	return (ft_strlen(str) + ft_strlen(new) - ft_strlen(old));
}

char	*str_replace(char *str, char *old, char *new)
{
	char	*new_str;
	bool	in_simple_quote;
	size_t	j;
	size_t	i;

	in_simple_quote = false;
	new_str = ft_calloc(get_new_str_size(str, old, new) + 1, sizeof(char));
	if (!new_str)
		return (NULL);
	i = 0;
	j = 0;
	while (str[i] && j <= get_new_str_size(str, old, new))
	{
		if (str[i] == '\'')
			in_simple_quote = !in_simple_quote;
		if (str[i] == '$' && !ft_strncmp(str + i, old, ft_strlen(old)) && !in_simple_quote)
		{
			j += ft_strlcpy(new_str + j, new, ft_strlen(new) + 1);
			j += ft_strlcpy(new_str + j, str + i + ft_strlen(old), ft_strlen(str));
			return (new_str);
		}
		new_str[j++] = str[i++];
	}
	return (new_str);
}
