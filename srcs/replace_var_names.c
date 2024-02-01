/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var_names.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:16:20 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 23:46:54 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	in_var_name(char c)
{
	return (ft_isalnum(c) || c == '_');
}

static char	*duplicate_var_name(char *str)
{
	char	*name;
	int	i;
	int	j;

	i = 1;
	while (str[i] && in_var_name(str[i]))
		i++;
	name = ft_calloc(i + 1, sizeof(char));
	name[0] = '$';
	i = 1;
	j = 1;
	while (str[i] && in_var_name(str[i]))
		name[j++] = str[i++];
	return (name);
}

static int	leave_quote(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\'')
		i++;
	if (!str[i])
		return (i);
	return (i + 1);
}

static char	*extract_var_name(char *str)
{
	int		i;
	bool	in_simple_quote;

	i = 0;
	in_simple_quote = false;
	while (str[i])
	{
		if (str[i] == '\'')
			in_simple_quote = !in_simple_quote;
		if (str[i] == '$' && str[i + 1] && str[i + 1] != ' ')
		{
			if (in_simple_quote)
			{
				i += leave_quote(str + i);
				if (!str[i])
					return (ft_strdup(""));
				in_simple_quote = false;
			}
			else
				return (duplicate_var_name(str + i));
		}
		i++;
	}
	return (ft_strdup(""));
}

char	*replace_var_names(char *input, t_env *env)
{
	char	*name;
	char	*value;
	char	*replaced;

	name = extract_var_name(input);
	if (!*name)
		return (free(name), ft_strdup(input));
	value = get_var_value(env, name + 1);
	replaced = str_replace(input, name, value);
	return (replaced);
}
