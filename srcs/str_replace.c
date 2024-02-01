/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_replace.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 21:32:02 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 21:49:17 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*str_replace(char *str, char *old, char *new)
{
	char	*new_str;
	size_t	size;
	size_t	j;
	size_t	i;

	size = ft_strlen(str) + ft_strlen(new) - ft_strlen(old);
	new_str = ft_calloc(size + 1, sizeof(char));
	i = 0;
	j = 0;
	while (str[i] && j < size)
	{
		if (!ft_strncmp(str + i, old, ft_strlen(old)))
		{
			ft_strlcpy(new_str + j, new, ft_strlen(new) + 1);
			return (new_str);
		}
		new_str[j++] = str[i++];
	}
	return (new_str);
}

int	main(int ac, char **av) {
	(void)ac;
	char *str = str_replace(av[1], av[2], av[3]);
	printf("%s\n", str);
	free(str);
}
