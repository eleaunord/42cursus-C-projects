/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:51:40 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/29 15:19:52 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	reverse(t_node **lst)
{
	t_node	*last;
	t_node	*tmp;

	last = *lst;
	tmp = *lst;
	while (last->next)
	{
		last = last->next;
		if (last->next == NULL)
			break ;
		tmp = tmp->next;
	}
	ft_add_front(lst, last);
	tmp->next = NULL;
}

void	rra(t_node **a)
{
	reverse(a);
	write(1, "rra\n", 4);
}

void	rrb(t_node **b)
{
	reverse(b);
	write(1, "rrb\n", 4);
}

void	rrr(t_node **a, t_node **b)
{
	reverse(a);
	reverse(b);
	write(1, "rrr\n", 4);
}
