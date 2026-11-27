/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yomafama <yomafama@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/20 15:15:13 by yomafama          #+#    #+#             */
/*   Updated: 2026/11/26 22:41:07 by yomafama         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stddef.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	int				value;
	int				rank;
	struct s_list	*next;
	struct s_list	*back;
}					t_list;

int	main(int ac, char **av);

void	simple(t_list **stack_a, t_list **stack_b, int n);
void	medium(t_list **stack_a, t_list **stack_b, int n);

// rules
void	swap(t_list *stack, int s);
void	push(t_list **dst, t_list **src, int s);
void	rotate(t_list **stack, int s);
void	r_rotate(t_list **stack, int s);

//algo_tools
void	rot_n(t_list **stack, int n, int s);
void	rrot_n(t_list **stack, int n, int s);

t_list	*make_stack(int ac, char **av);
// stack
void	ft_free_stack(t_list **head);
void	ft_free_ar(char **s);
long	ft_atoi(const char *nptr);
char	**ft_ar(int ac, char **av);
int		ft_strlen(char *s);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_split(char const *s, char c);


#endif
