/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:34:12 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 16:35:27 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	display_env(t_env *env)
{
	while (env)
	{
		printf("%s=%s\n", env->name, env->value);
		env = env->next;
	}
}

void	free_env(t_env *env)
{
	t_env	*tmp;

	while (env)
	{
		tmp = env;
		env = env->next;
		free(tmp->value);
		free(tmp->name);
		free(tmp);
	}
}

char	*extract_env_value(char *name, t_env *env)
{
	int	i;

	i = 0;
	if (*name == '$')
		i++;
	while (env)
	{
		if (!ft_strcmp(name + i, env->name))
			return (env->value);
		env = env->next;
	}
	return ("");
}
