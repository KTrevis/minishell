/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 12:09:43 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/06 14:48:03 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

int	parse_input(char *input, t_env *env)
{
	input = replace_var_names(input, env);
	if (!input)
		return (-1);
	printf("%s\n", input);
	free(input);
	return (0);
}
