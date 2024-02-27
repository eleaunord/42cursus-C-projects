/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:51:50 by eleroty           #+#    #+#             */
/*   Updated: 2024/02/03 14:45:28 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case_1(t_node **lst)
{
	sa(lst);
	ra(lst);
}

void	case_2(t_node **lst)
{
	t_node			*head;
	t_min_values	min_values;

	head = *lst;
	min_values = find_min(*lst);
	if (head->next->content == min_values.min)
		sa(lst);
	else
		rra(lst);
}

void	case_3(t_node **lst)
{
	t_node			*head;
	t_min_values	min_values;

	head = *lst;
	min_values = find_min(*lst);
	if (head->next->content == min_values.min)
		ra(lst);
	else
	{
		sa(lst);
		rra(lst);
	}
}

void	sort_3(t_node **lst)
{
	t_node			*head;
	t_min_values	min_values;

	head = *lst;
	min_values = find_min(*lst);
	if (is_sorted(lst))
		return ;
	if (head->content == min_values.min
		&& head->next->content != min_values.next_min)
		case_1(lst);
	else if (head->content == min_values.next_min)
		case_2(lst);
	else
		case_3(lst);
}
