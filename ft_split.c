/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jesroble <jesroble@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:07:00 by jesroble          #+#    #+#             */
/*   Updated: 2024/06/02 17:23:50 by jesroble         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	*free_split(char **split)
{
	int	i;

	i = 0;
	while (split && split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
	return (NULL);
}

static int	count_words(char const	*s, char c)
{
	int	i;
	int	words;

	i = 0;
	words = 0;
	if (!*s)
		return (0);
	while (s[i])
	{
		while (s[i] == c)
		{
			i++;
		}
		if (s[i] != '\0')
		{
			words++;
			while (s[i] != c && s[i] != '\0')
			{
				i++;
			}
		}
	}
	return (words);
}

static char	*word_dup(char **split, char const *s, int start, int end)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc(((end - start) + 1) * sizeof(char));
	if (!word)
		return (free_split(split));
	while (start < end)
		word[i++] = s[start++];
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *s, char c)
{
	char	**split;
	size_t	i;
	size_t	w;
	int		index;

	split = (char **)malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!split || !s)
		return (NULL);
	i = 0;
	w = 0;
	index = -1;
	while (i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			split[w++] = word_dup(split, s, index, i);
			index = -1;
		}
		i++;
	}
	split[w] = NULL;
	return (split);
}

/* int	main(void)
{
	char	c = ' ';
	char	s[] = " ";
	char	**split = ft_split(s, c);

	while(split[i] != NULL)
	{
		printf("%s\n", split[i]);
		free (split[i]);
		i++;
	}
	free(split);
} */
