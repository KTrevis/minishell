/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:13:01 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/02 10:01:37 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_input(char *input, t_env *env)
{
	char	*replaced;
	char	*old;

	old = input;
	replaced = replace_var_names(input, env);
	if (!replaced)
		return (0);
	while (ft_strcmp(old, replaced))
	{
		if (old != input)
			free(old);
		old = replaced;
		replaced = replace_var_names(old, env);
		if (!replaced)
			return (free(input), free(old), 0);
	}
	printf("%s\n", replaced);
	free(input);
	free(replaced);
	return (1);
}
