/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 13:10:04 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/09 14:02:17 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"
#include <readline/readline.h>

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

static int	create_childs(char ***split, char **env, t_env *env_list)
{
	int		i;
	pid_t	pid;

	i = 0;
	while (split[i])
	{
		pid = fork();
		if (pid == -1)
			return (0);
		if (pid == 0)
		{
			free_env_list(env_list);
			run_command(split[i], env);
			free_split_split(split);
			free_split(env);
			rl_clear_history();
			exit(0);
		}
		i++;
	}
	return (1);
}

static void	wait_childs(char ***split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		waitpid(-1, NULL, 0);
		i++;
	}
}

int	exec(char ***split, t_env *env_list)
{
	char	**env;

	if (!split)
		return (EXIT);
	env = env_to_split(env_list);
	create_childs(split, env, env_list);
	wait_childs(split);
	free_split(env);
	free_split_split(split);
	return (SUCCESS);
}
