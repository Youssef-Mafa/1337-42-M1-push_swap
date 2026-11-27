/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:11:19 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/26 21:54:27 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	findm(t_list *stack)
{
	t_list	*tmp;
	int		i;
	int		j;
	int		v;

	i = 0;
	j = 0;
	v = stack->value;
	tmp = stack;
	while (tmp->next != stack)
	{
		tmp = tmp->next;
		i++;
		if (v > tmp->value)
		{
			v = tmp->value;
			j = i;
		}
	}
	return (j);
}

void	simple(t_list **stack_a, t_list **stack_b, int n)
{
	int	min;
	int	i;

	i = n;
	while (i > 1)
	{
		min = findm(*stack_a);
		if (min <= i / 2)
			rot_n(stack_a, min, 1);
		else
			rrot_n(stack_a, (i - min), 1);
		push(stack_b, stack_a, 2);
		i--;
	}
	while (i <= n)
	{
		push(stack_a, stack_b, 1);
		i++;
	}
}
