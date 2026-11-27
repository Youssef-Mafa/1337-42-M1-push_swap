/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   medium.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/26 16:21:42 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/27 12:36:16 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_root(int n)
{
	int	i;
	i = 0;

	while (i * i <= n)
		i++;
	return (i - 1);
}

int	find_chunk(t_list *stack_a, int min, int max)
{
	t_list	*f;
	t_list	*b;
	int		i;
	int		j;

	f = stack_a;
	b = stack_a;
	i = 0;
	j = 0;
	while (1)
	{
		if (f->rank >= min && f->rank < max)
			return(i);
		if (b->rank >= min && b->rank < max)
			return(j);
		f = f->next;
		b = b->back;
		i++;
		j--;
	}
}

void	push_chun(t_list **stack_a, t_list **stack_b, int r, int x)
{
	int	i;
	int	j;

	i = r;
	while (i)
	{
		j = find_chunk(*stack_a, r * (x - 1), r * x);
		if (j >= 0)
			rot_n(stack_a, j, 1);
		else if (j < 0)
			rrot_n(stack_a, -j, 1);
		push(stack_b, stack_a, 2);
		i--;
	}
}

void	medium(t_list **stack_a, t_list **stack_b, int n)
{
	int	r;
	int	x;
	int	j;

	r = ft_root(n);
	x = 1;
	while (r * x <= n)
	{
		push_chun(stack_a, stack_b, r, x);
		x++;
	}
	while (*stack_a)
		push(stack_b, stack_a, 2);
	j = 0;
	while (n > 0)
	{
		j = find_chunk(*stack_b, n - 1, n);
		if (j >= 0)
			rot_n(stack_b, j, 2);
		else if (j < 0)
			rrot_n(stack_b, -j, 2);
		push(stack_a, stack_b, 1);
		n--;
	}
}
