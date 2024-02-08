/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_split.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/07 18:20:53 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/08 11:46:46 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	count_words(char *input)
{
	int		i;
	int		words;
	char	quote;

	i = 0;
	words = 1;
	quote = 0;
	while (input[i])
	{
		if (input[i] == '\'' || input[i] == '"')
		{
			if (quote == input[i])
				quote = 0;
			else if (!quote)
				quote = input[i];
		}
		if (input[i] == '|' && !quote)
			words++;
		i++;
	}
	return (words);
}

static void	set_quote(char c, char *quote)
{
	if (c == '\'' || c == '"')
	{
		if (c == *quote)
			*quote = 0;
		else if (!*quote)
			*quote = c;
	}
}

static int	word_size(char *input, int i, char quote)
{
	int	size;

	size = 0;
	while (input[i])
	{
		set_quote(input[i], &quote);
		if (input[i] == '|' && !quote)
			return (size);
		i++;
		size++;
	}
	return (size);
}

static char	*new_word(char *input, int *i, char *quote)
{
	char	*word;
	int		j;

	j = 0;
	word = ft_calloc(word_size(input, *i, *quote) + 1, sizeof(char));
	while (input[*i])
	{
		set_quote(input[*i], quote);
		if (input[*i] == '|' && !*quote)
			return (word);
		word[j++] = input[(*i)++];
	}
	return (word);
}

char	**pipe_split(char *input)
{
	int		i;
	int		j;
	char	**split;
	char	quote;

	i = 0;
	j = 0;
	quote = 0;
	split = ft_calloc(count_words(input) + 1, sizeof(char *));
	while (input[i])
	{
		set_quote(input[i], &quote);
		if (!quote && input[i] != '|' && (i == 0 || input[i - 1] == '|'))
		{
			split[j++] = new_word(input, &i, &quote);
			if (!split[j - 1])
				return (free_split(split), NULL);
		}
		i++;
	}
	return (split);
}