/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:09:18 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/05 12:09:19 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

void	quit_shell(t_env *env)
{
	printf("exit\n");
	free_env_list(env);
	exit(0);
}

static void	catch_sigint(int sig)
{
	(void)sig;
	rl_on_new_line();
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
}

void	input(t_env *env)
{
	char	*input;

	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			quit_shell(env);
		parse_input(input, env);
	}
}
