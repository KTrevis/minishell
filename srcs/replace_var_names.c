/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var_names.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:16:20 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 22:34:39 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*duplicate_var_name(char *str)
{
	char	*name;
	int	i;

	i = 1;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	name = ft_calloc(i + 1, sizeof(char));
	name[0] = '$';
	i = 1;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
	{
		name[i] = str[i];
		i++;
	}
	return (name);
}

static char	*extract_var_name(char *str, bool *in_simple_quote)
{
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\'')
			*in_simple_quote = !*in_simple_quote;
		if (str[i] == '$' && str[i + 1] && str[i + 1] != ' ')
			return (duplicate_var_name(str + i));
		i++;
	}
	return (NULL);
}

char	*replace_var_names(char *input)
{
	bool	in_simple_quote;
	char	*name;

	name = extract_var_name(input, &in_simple_quote);
	printf("%s\n", name);
	return (name);
}
