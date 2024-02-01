/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   replace_var_split.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 15:27:54 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 16:32:41 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*get_variable_value(char *name, t_env *env)
{
	char	*value;

	if (!name)
		return (NULL);
	value = get_env_value(name, env);
	free(name);
	return (value);
}

static int insert_value(char *str, int *i, char *new_str, char *value)
{
	int	j;

	j = 0;
	while (str[*i] && str[*i] != ' ')
		(*i)++;
	while (value[j])
	{
		new_str[j] = value[j];
		j++;
	}
	return (j);
}

static char	*apply_value(char *str, char *value, int len)
{
	char	*new_str;
	int		i;
	int		j;

	new_str = ft_calloc(len + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1]
			&& str[i + 1] != ' ')
			j += insert_value(str, &i, new_str + j, value);
		new_str[j++] = str[i++];
	}
	return (new_str);
}

static char	*replace_name(char *str, t_env *env)
{
	char	*new_str;
	char	*value;
	char	*name;
	int		len;

	name = isolate_var_name(str);
	if (!name)
		return (free(str), NULL);
	value = get_variable_value(name, env);
	if (!value)
		return (free(str), free(name), NULL);
	len = ft_strlen(str) - ft_strlen(name) + ft_strlen(value);
	new_str = apply_value(str, value, len);
	free(name);
	free(value);
	free(str);
	return (new_str);
}

char	*replace_var_split(char *str, t_env *env)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$' && str[i + 1]
			&& str[i + 1] != ' ')
		{
			str = replace_name(str, env);
			if (!str)
				return (NULL);
			i = 0;
		}
		i++;
	}
	return (str);
}
