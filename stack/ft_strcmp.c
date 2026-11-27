/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:34:30 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/24 14:49:49 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int		g;

	g = 0;
	while (s1[g] && s2[g] && s1[g] == s2[g])
	{
		g++;
	}
	return ((unsigned char)(s1[g]) - (unsigned char)(s2[g]));
}
