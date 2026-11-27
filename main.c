/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 21:08:34 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/27 12:33:11 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	node_count(t_list *a)
{
	t_list	*tmp;
	int		i;

	tmp = a->next;
	i = 1;
	while(tmp != a)
	{
		tmp = tmp ->next;
		i++;
	}
	return (i);
}

//####################################

static void	print_stack(t_list *head)
{
	t_list	*curr;

	if (!head)
	{
		return ;
	}
	curr = head;
	while (1)
	{
		printf("%d ", curr->value);
		curr = curr->next;
		if (curr == head)
			break ;
	}
	printf("\n");
}

int	main(int ac, char **av)
{
	t_list	*a;
	t_list	*b;
	int		n;

	if (ac < 2)
		return (0);
	a = make_stack(ac, av);
	if (!a)
		return (0);
	b = NULL;
	n = node_count(a);
	// print_stack(a);
	// print_stack(b);
	medium(&a, &b, n);
	print_stack(a);
	// print_stack(b);
	ft_free_stack(&a);
}
