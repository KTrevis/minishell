/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 10:13:14 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/02 11:05:23 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_split	*add_string(t_split *split, char *str)
{
	t_split	*new;
	t_split	*curr;

	if (!str)
		return (NULL);
	new = ft_calloc(1, sizeof(t_split));
	if (!new)
		return (free(str), new);
	new->str = str;
	if (!split)
		split = new;
	else
	{
		curr = split;
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	return (split);
}

static int	new_world_len(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != c)
		i++;
	return (i);
}

static char	*new_word(char *str, int *i)
{
	char	*word;
	char	c;
	int		j;

	c = ' ';
	if (str[*i] == '"' || str[*i] == '\'')
	{
		c = str[*i];
		(*i)++;
	}
	word = ft_calloc(new_world_len(str + *i, c) + 1, sizeof(char));
	j = 0;
	while (str[*i] && str[*i] != c)
		word[j++] = str[(*i)++];
	if (str[*i] == c)
		(*i)++;
	return (word);
}

void	free_shell_split(t_split *split)
{
	t_split	*tmp;

	while (split)
	{
		tmp = split;
		split = split->next;
		free(tmp->str);
		free(tmp);
	}
}

t_split	*shell_split(char *str)
{
	t_split	*split;
	int		i;

	i = 0;
	split = NULL;
	while (str[i])
	{
		if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
			split = add_string(split, new_word(str, &i));
		if (!str[i])
			break ;
		i++;
	}
	return (split);
}
