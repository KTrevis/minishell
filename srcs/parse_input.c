/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 22:13:01 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 23:24:33 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	parse_input(char *input, t_env *env)
{
	char	*replaced;

	replaced = replace_var_names(input, env);
	printf("%s\n", replaced);
	free(replaced);
	return (1);
}
