/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ar.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 13:40:05 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/25 16:23:44 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	check_dup(char **s)
{
	int	i;
	int	j;

	i = 0;
	while (s[i + 1])
	{
		j = i;
		while (s[++j])
			if (!ft_strcmp(s[i], s[j]))
				return (1);
		i++;
	}
	return (0);
}

char	**ft_ar(int ac, char **av)
{
	int		g;
	char	*p;
	char	**ar;

	p = NULL;
	g = 1;
	while (g < ac)
	{
		p = ft_strjoin(p, av[g]);
		if (ft_strcmp(p, "Error") == 0)
			return (write(1, "Error", 5), NULL);
		g++;
	}
	ar = ft_split(p, ' ');
	if (check_dup(ar))
	{
		ft_free_ar(ar);
		free(p);
		return (write(1, "Error", 5), NULL);
	}
	free(p);
	return (ar);
}
