/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:20:06 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 13:55:15 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include "libft.h"

typedef struct s_env
{
	char			*name;
	char			*value;
	struct s_env	*next;
}	t_env;

t_env	*split_env(char **env);
void	free_env(t_env *env);
void	display_env(t_env *env);
void	input(t_env *env);
int		parse_input(char *input, t_env *env);
t_list	*shell_split(char *input, t_env *env);
void	free_shell_split(t_list *head);

#endif
