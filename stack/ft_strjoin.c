/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:34:45 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/24 16:01:23 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_isalpha(char *s)
{
	int	g;

	if (s[0] == '\0')
		return (1);
	g = 0;
	while (s[g])
	{
		if (!(s[g] >= '0' && s[g] <= '9') && s[g] != ' '
			&& s[g] != '+' && s[g] != '-')
			return (1);
		if ((s[g] == '+' || s[g] == '-')
			&& !(s[g + 1] >= '0' && s[g + 1] <= '9'))
			return (1);
		g++;
	}
	return (0);
}

char	*s1_allocation(char *s)
{
	char	*p;
	int		g;

	if (ft_isalpha(s) == 1)
		return ("Error");
	p = malloc(ft_strlen(s) + 1);
	if (!p)
		return (NULL);
	g = 0;
	while (s[g])
	{
		p[g] = s[g];
		g++;
	}
	p[g] = '\0';
	return (p);
}

int	len_only(char *s)
{
	int	g;
	int	n;
	int	i;

	if (!s)
		return (0);
	g = 0;
	i = 0;
	n = 0;
	while (s[g])
	{
		if (s[g] != ' ' && (g == 0 || s[g - 1] == ' '))
			i++;
		if (s[g] != ' ')
			n++;
		g++;
	}
	return (n + (i - 1));
}

char	*strjoin_help(char *s, char *p, int *n)
{
	int		g;

	g = 0;
	while (s[g])
	{
		if (s[g] && s[g] != ' ')
		{
			p[(*n)++] = s[g++];
			if (s[g] == ' ')
				p[(*n)++] = ' ';
		}
		else
			g++;
	}
	return (p);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		n;

	if (!s2)
		return (NULL);
	if (!s1)
		return (s1_allocation(s2));
	if (ft_isalpha(s2) == 1)
		return (free(s1), "Error");
	p = malloc ((len_only(s1) + len_only(s2)) + 2);
	if (p == NULL)
		return (NULL);
	n = 0;
	strjoin_help(s1, p, &n);
	p[n++] = ' ';
	strjoin_help(s2, p, &n);
	p[n] = '\0';
	free (s1);
	return (p);
}
