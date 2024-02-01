/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:38:28 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 15:08:21 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

static void	catch_sigint()
{
	rl_on_new_line();
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
}

void	quit_shell(t_env *env)
{
	free_env(env);
	printf("exit\n");
	exit(0);
}

void	input(t_env *env)
{
	char	*input;

	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		input = readline("minishell> ");
		if (!input || !parse_input(input, env))
			quit_shell(env);
		free(input);
	}
}
