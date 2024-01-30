/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:25:27 by ketrevis          #+#    #+#             */
/*   Updated: 2024/01/30 16:25:49 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <readline/readline.h>
#include <signal.h>

void	ctrl_c(int sig)
{
	(void)sig;
	rl_on_new_line();
	printf("\n");
	rl_redisplay();
}

int	main(int ac, char **av, char **env)
{
	char	*input;

	(void)ac;
	(void)av;
	(void)env;
	signal(SIGQUIT, SIG_IGN);
	signal(SIGINT, ctrl_c);
	while (1)
	{
		input = readline("minishell> ");
		if (!input)
			return (0);
		free(input);
	}
}
