/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 16:14:51 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/25 15:29:00 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_list *stack, int s)
{
	int		tmp;
	t_list	*second;

	if (!stack || stack->next == stack)
		return ;
	second = stack->next;
	tmp = stack->value;
	stack->value = second->value;
	second->value = tmp;
	tmp = stack->rank;
	stack->rank = second->rank;
	second->rank = tmp;
	if (s == 1)
		write(1, "sa\n", 3);
	else if (s == 2)
		write(1, "sb\n", 3);
}
