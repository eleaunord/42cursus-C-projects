/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:52:19 by eleroty           #+#    #+#             */
/*   Updated: 2024/02/01 18:32:16 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

bool	is_sorted(t_node **stack)
{
	t_node	*head;

	head = *stack;
	while (head && head->next)
	{
		if (head->content > head->next->content)
			return (false);
		head = head->next;
	}
	return (true);
}

t_max_values	find_max(t_node *head)
{
	t_max_values	result;

	result.max = INT_MIN;
	result.next_max = INT_MIN;
	while (head != NULL)
	{
		if (head->content > result.max)
		{
			result.next_max = result.max;
			result.max = head->content;
		}
		else if (head->content > result.next_max && head->content != result.max)
		{
			result.next_max = head->content;
		}
		head = head->next;
	}
	return (result);
}

t_min_values	find_min(t_node *head)
{
	t_min_values	result;

	result.min = INT_MAX;
	result.next_min = INT_MAX;
	while (head != NULL)
	{
		if (head->content < result.min)
		{
			result.next_min = result.min;
			result.min = head->content;
		}
		else if (head->content < result.next_min && head->content != result.min)
		{
			result.next_min = head->content;
		}
		head = head->next;
	}
	return (result);
}
