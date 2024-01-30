/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 13:59:44 by ketrevis          #+#    #+#             */
/*   Updated: 2024/01/30 14:42:39 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

uint	find_next_quote(char *str, uint *i)
{
	char	c;

	c = str[*i];
	(*i)++;
	while (str[*i])
	{
		if (str[*i] == c)
			return (*i);
		(*i)++;
	}
	return (0);
}

uint	count_words(char *str)
{
	uint	i;
	uint	words;

	i = 0;
	words = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
				words++;
			if (!find_next_quote(str, &i))
				return (words);
		}
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			words++;
		i++;
	}
	return (words);
}

char	*new_quoted_word(char *str, uint *i)
{
	char	*word;
	char	c;
	int		j;

	c = str[*i];
	(*i)++;
	j = *i;
	while (str[j] && str[j] != c)
		j++;
	word = ft_calloc(j + 1, sizeof(char));
	if (!word)
		return (NULL);
	j = 0;
	while (str[*i] && str[*i] != c)
		word[j++] = str[(*i)++];
	if (str[*i] == c)
		(*i)++;
	return (word);
}

int	fill_split(char *str, char **split)
{
	uint	i;
	uint	j;
	char	c;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"' || str[i] == '\'')
		{
			c = str[i];
			split[j++] = new_quoted_word(str, &i);
			if (!ft_strchr(str + i, c) || !split[j - 1])
				break ;
		}
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		{
			split[j++] = new_word(str + i, ' ');
			if (!split[j - 1])
				return (1);
		}
		i++;
	}
	return (split[j - 1] == NULL);
}

char	**echo_split(char *str)
{
	char	**split;
	int		ret;

	split = ft_calloc(count_words(str) + 1, sizeof(char *));
	if (!split)
		return (NULL);
	ret = fill_split(str, split);
	if (ret == 1)
		return (free_split(split), NULL);
	return (split);
}

int	main(int ac, char **av)
{
	(void)ac;
	char **split = echo_split(av[1]);
	for (int i = 0; split[i]; i++)
		ft_printf("%s\n", split[i]);
	free_split(split);
}
