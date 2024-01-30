/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 16:36:04 by ketrevis          #+#    #+#             */
/*   Updated: 2024/01/30 18:10:03 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "minishell.h"

void	ft_echo(char *input)
{
	char	**split;
	uint	i;
	bool	flag;

	flag = false;
	split = echo_split(input);
	i = 1;
	while (split[i])
	{
		if (split[i][0] == '\'')
			write(1, split[i] + 1, ft_strlen(split[i]) - 2);
		else
			write(1, split[i], ft_strlen(split[i]));
		write(1, " ", 1);
		i++;
	}
	if (!flag)
		printf("\n");
}
