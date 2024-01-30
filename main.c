/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:25:27 by ketrevis          #+#    #+#             */
/*   Updated: 2024/01/30 20:07:24 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>

void	ctrl_c(int sig)
{
	(void)sig;
	rl_on_new_line();
	printf("\n");
	rl_replace_line("", 0);
	rl_redisplay();
}

void	quit_shell()
{
	exit(0);
}

int	main(int ac, char **av, char **env)
{
	char	*input;
	t_env	*env_list;

	(void)ac;
	(void)av;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c);
	env_list = split_env(env);
	if (!env_list)
		return (0);
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			quit_shell();
		parse_input(input);
		free(input);
	}
}
