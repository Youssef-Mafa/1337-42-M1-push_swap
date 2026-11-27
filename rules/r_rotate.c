/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 15:02:52 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/24 16:06:15 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	r_rotate(t_list **stack, int s)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->back;
	if (s == 1)
		write(1, "rra\n", 4);
	else if (s == 2)
		write(1, "rrb\n", 4);
}
