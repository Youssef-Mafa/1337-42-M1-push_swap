/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:44:45 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/24 14:49:53 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static char	*ft_putword(char const *s, char c)
{
	int		i;
	int		l;
	char	*word;

	l = 0;
	while (s[l] != '\0' && s[l] != c)
		l++;
	word = malloc(l + 1);
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < l)
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

static int	ft_nw(char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			w++;
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (w);
}

static int	ft_fill(char **words, char const *s, char c, int w)
{
	int	i;

	i = 0;
	words[w] = ft_putword(s, c);
	if (words[w] == NULL)
	{
		while (i < w)
		{
			free(words[i]);
			i++;
		}
		free(words);
		return (0);
	}
	w++;
	return (w);
}

static int	ft_nextword(char **words, char const *s, char c)
{
	int	i;
	int	w;

	i = 0;
	w = 0;
	while (s[i] != '\0')
	{
		while (s[i] != '\0' && s[i] == c)
			i++;
		if (s[i] != '\0' && s[i] != c)
			w = ft_fill(words, &s[i], c, w);
		if (w == 0)
			return (0);
		while (s[i] != '\0' && s[i] != c)
			i++;
	}
	return (w);
}

char	**ft_split(char const *s, char c)
{
	char	**words;
	int		nw;
	int		w;

	if (s == NULL)
		return (NULL);
	nw = ft_nw(s, c);
	words = malloc(sizeof(char *) * (nw + 1));
	if (words == NULL)
		return (NULL);
	w = 0;
	if (nw != 0)
	{
		w = ft_nextword(words, s, c);
		if (w == 0)
			return (NULL);
	}
	words[w] = NULL;
	return (words);
}
