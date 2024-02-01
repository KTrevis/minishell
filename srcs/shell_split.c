/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:53:47 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 14:15:09 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_split	*add_string(t_split *head, char *str)
{
	t_split	*new;
	t_split	*curr;

	curr = head;
	new = ft_calloc(1, sizeof(t_split));
	if (!new)
		return (NULL);
	if (!head)
		head = new;
	else
	{
		while (curr->next)
			curr = curr->next;
		curr->next = new;
	}
	new->str = str;
	return (head);
}

int	is_word_start(char *str, int i)
{
	if (str[i] != ' ' && (i == 0 || str[i - 1] == ' '))
		return (1);
	if ((i == 0 || str[i - 1] == ' ') && (str[i] == '"' || str[i] == '\''))
		return (1);
	return (0);
}

static char	*new_word(char *input, int *i)
{
	char	*str;
	char	c;
	int		j;

	j = *i;
	c = ' ';
	if (input[j] == '"' || input[j] == '\'')
	{
		c = input[j];
		j++;
		(*i)++;
	}
	while (input[j] && input[j] != c)
		j++;
	str = ft_calloc(j + 1, sizeof(char));
	j = 0;
	while (input[*i] && input[*i] != c)
	{
		if (input[*i] != '\'' && input[*i] != '"')
			str[j++] = input[(*i)];
		(*i)++;
	}
	return (str);
}

t_split	*shell_split(char *input, t_env *env)
{
	t_split	*split;
	int		i;

	(void)env;
	i = 0;
	split = NULL;
	while (input[i])
	{
		if (is_word_start(input, i))
			split = add_string(split, new_word(input, &i));
		if (!input[i])
			break ;
		i++;
	}
	return (split);
}
