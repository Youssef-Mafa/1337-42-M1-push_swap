/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 18:55:45 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/24 16:06:11 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	out_src(t_list **src,t_list *tmp)
{
	if (tmp == tmp->next)
	{
		*src = NULL;
		return ;
	}
	tmp->back->next = tmp->next;
	tmp->next->back = tmp->back;
	*src = tmp->next;
}

void	in_dst(t_list **dst,t_list *tmp)
{
	if (!*dst)
	{
		*dst = tmp;
		tmp->next = tmp;
		tmp->back = tmp;
		return ;
	}
	tmp->back = (*dst)->back;
	tmp->next = *dst;
	(*dst)->back->next = tmp;
	(*dst)->back = tmp;
	*dst = tmp;
}

void	push(t_list **dst, t_list **src, int s)
{
	t_list	*tmp;

	if (!*src)
		return;
	tmp = *src;
	out_src(src, tmp);
	in_dst(dst, tmp);
	if (s == 1)
		write(1, "pa\n", 3);
	else if (s == 2)
		write(1, "pb\n", 3);
}
