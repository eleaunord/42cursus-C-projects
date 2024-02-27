/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:13:43 by eleroty           #+#    #+#             */
/*   Updated: 2024/02/03 15:08:08 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	set_index(t_node *stack)
{
	int	median;
	int	i;

	median = ft_size(stack) / 2;
	i = 0;
	stack->first_half = false;
	if (!stack)
		return ;
	while (stack != NULL)
	{
		stack->index = i;
		if (i <= median)
			stack->first_half = true;
		else
			stack->first_half = false;
		stack = stack->next;
		i++;
	}
}

void	set_target_a_to_b(t_node *a, t_node *b)
{
	int				closest_smallest;
	t_max_values	max_values;
	t_node			*target;

	max_values = find_max(b);
	while (a)
	{
		closest_smallest = INT_MIN;
		target = find_target_node_in_b(a, b, &closest_smallest);
		if (target == NULL)
			target = find_content_node(&b, max_values.max);
		a->target_node = target;
		a = a->next;
	}
}

// target node = closest biggest node to b in a
// if we can't find the closest smaller node then the target node is min value
void	set_target_b_to_a(t_node *a, t_node *b)
{
	int				closest_biggest;
	t_min_values	min_values;
	t_node			*current_a;
	t_node			*target;

	min_values = find_min(a);
	while (b)
	{
		closest_biggest = INT_MAX;
		current_a = a;
		target = find_target_node_in_a(b, a, &closest_biggest);
		if (target == NULL)
			target = find_content_node(&a, min_values.min);
		b->target_node = target;
		b = b->next;
	}
}

void	set_cheapest(t_node *stack)
{
	long	cheapest_value;
	t_node	*cheapest_node;

	cheapest_node = NULL;
	if (!stack)
		return ;
	cheapest_value = LONG_MAX;
	while (stack)
	{
		if (stack->push_cost < cheapest_value)
		{
			cheapest_value = stack->push_cost;
			cheapest_node = stack;
		}
		stack = stack->next;
	}
	cheapest_node->cheapest = true;
}
