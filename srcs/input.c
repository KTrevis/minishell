/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:09:18 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/07 09:54:04 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

void	quit_shell(t_env *env)
{
	printf("exit\n");
	free_env_list(env);
	rl_clear_history();
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
	t_input	res;

	signal(SIGINT, catch_sigint);
	signal(SIGQUIT, SIG_IGN);
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			quit_shell(env);
		add_history(input);
		res = parse_input(input, env);
	}
}
