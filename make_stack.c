/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/23 22:53:51 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/25 19:22:30 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_new_node(int	va)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->value = va;
	node->rank = -1;
	node->next = node;
	node->back = node;
	return (node);
}

int	ft_add_back(t_list **stack, int va)
{
	t_list	*new_node;

	new_node = ft_new_node(va);
	if (!new_node)
		return (ft_free_stack(stack), 0);
	if (!(*stack))
	{
		*stack = new_node;
		return (1);
	}
	new_node->next = *stack;
	new_node->back = (*stack)->back;
	(*stack)->back = new_node;
	new_node->back->next = new_node;
	return (1);
}

int	new_stack(t_list **stack, char **ar)
{
	int	i;
	long	va;

	i = 0;
	while (ar[i])
	{
		va = ft_atoi(ar[i]);
		if (va > 2147483647 || va < -2147483648)
		{
			ft_free_stack(stack);
			write(2, "Error\n", 6);
			return (0);
		}
		if (!ft_add_back(stack, va))
			return (0);
		i++;
	}
	return (1);
}

void	ft_rank(t_list *stack)
{
	t_list	*tmp;
	t_list	*min;
	int		i;

	i = 0;
	while (1)
	{
		tmp = stack;
		while (tmp->rank != -1 && tmp->next != stack)
			tmp = tmp->next;
		min = tmp;
		while (1)
		{
			if (min->value > tmp->value && tmp->rank == -1)
				min = tmp;
			tmp = tmp->next;
			if (tmp == stack)
				break;
		}
		if (min->rank != -1)
			return;
		min->rank = i;
		i++;
	}
}

t_list	*make_stack(int ac, char **av)
{
	char	**ar;
	t_list	*stack;

	stack = NULL;
	ar = ft_ar(ac, av);
	if (!ar)
		return (0);
	new_stack(&stack, ar);
	ft_rank(stack);
	ft_free_ar(ar);
	return (stack);
}
