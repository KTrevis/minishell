/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 20:54:00 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 21:17:42 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_replace(char *str, char *old, char *new)
{
	size_t	i;
	size_t	j;
	size_t	size;
	char	*new_str;

	size = ft_strlen(str) + ft_strlen(new) - ft_strlen(old);
	new_str = ft_calloc(size + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (!ft_strncmp(str + i, old, ft_strlen(old)))
			j += ft_strlcpy(new_str + j, new, ft_strlen(new) + 1);
		if (j >= size)
			break ;
		new_str[j++] = str[i++];
	}
	return (new_str);
}
