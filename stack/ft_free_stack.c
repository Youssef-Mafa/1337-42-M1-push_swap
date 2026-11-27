/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_stack.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/24 20:40:08 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/24 20:40:57 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_free_stack(t_list **head)
{
	t_list	*curr;
	t_list	*next;

	if (!*head)
		return ;
	curr = (*head)->next;
	while(curr != *head)
	{
		next = curr->next;
		free(curr);
		curr = next;
	}
	free(*head);
	*head = NULL;
}
