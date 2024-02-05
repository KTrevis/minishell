/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:09:43 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/05 19:29:37 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

static char	*isolate_var_name(char *input)
{
	int		i;
	char	*str;

	i = 0;
	while (input[i] && (ft_isalnum(input[i]) || input[i] == '_'))
		i++;
	str = ft_calloc(i + 1, sizeof(char));
	if (!str)
		return (NULL);
	i = 0;
	while (input[i])
	{
		str[i] = input[i];
		i++;
	}
	return (str);
}

static int	get_replaced_size(char *input, t_env *env)
{
	int		i;
	int		len;
	char	*name;

	i = 0;
	len = 0;
	while (input[i])
	{
		if (input[i] == '$' && input[i + 1] != ' ')
		{
			name = isolate_var_name(input + i + 1);
			free(name);
		}
		i++;
	}
	return (len);
}

static char	*replace_var_names(char *input, t_env *env)
{
	int		i;
	int		len;
	bool	in_simple_quote;

	i = 0;
	in_simple_quote = false;
	while (input[i])
	{
		i++;
	}
	return (str);
}

int	parse_input(char *input, t_env *env)
{
	char	**split;

	input = replace_var_names(input, env);
	split = ft_split(input, '|');
	if (!split)
		return (1);
	return (0);
}
