/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 15:20:06 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 16:36:06 by ketrevis         ###   ########.fr       */
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

typedef struct s_split
{
	char			*str;
	struct s_split	*next;
}	t_split;

t_env	*split_env(char **env);
void	free_env(t_env *env);
void	display_env(t_env *env);
void	input(t_env *env);
int		parse_input(char *input, t_env *env);
t_split	*shell_split(char *input, t_env *env);
void	free_shell_split(t_split *head);
void	ft_echo(t_split *split);
char	*isolate_var_name(char *str);
char	*replace_var_split(char *str, t_env *env);
char	*extract_env_value(char *name, t_env *env);

#endif
