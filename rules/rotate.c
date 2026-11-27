/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 20:42:33 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/24 16:06:19 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_list **stack, int s)
{
	if (!*stack || (*stack)->next == *stack)
		return ;
	*stack = (*stack)->next;
	if (s == 1)
		write(1, "ra\n", 3);
	else if (s == 2)
		write(1, "rb\n", 3);
}
