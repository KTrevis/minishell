/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shell_split.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ketrevis <ketrevis@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/01 12:53:47 by ketrevis          #+#    #+#             */
/*   Updated: 2024/02/01 13:50:55 by ketrevis         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_list	*add_string(t_list *head, char *str)
{
	t_list	*new;
	t_list	*curr;

	curr = head;
	new = ft_calloc(1, sizeof(t_list));
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
	new->content = str;
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
		str[j++] = input[(*i)++];
	return (str);
}

t_list	*shell_split(char *input, t_env *env)
{
	t_list	*split;
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
