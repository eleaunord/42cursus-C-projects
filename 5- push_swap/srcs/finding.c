/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   finding.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 14:14:40 by eleroty           #+#    #+#             */
/*   Updated: 2024/02/01 18:39:04 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

t_node	*find_content_node(t_node **a, int value)
{
	t_node	*current;

	current = *a;
	while (current != NULL)
	{
		if (current->content == value)
			return (current);
		current = current->next;
	}
	return (NULL);
}

//find index stack b
int	find_index_b(t_node **stack, int value)
{
	t_node	*current;
	int		i;

	i = 0;
	current = *stack;
	while (current != NULL)
	{
		if (current->content == value)
			break ;
		current = current->next;
		i++;
	}
	return (i);
}

t_node	*get_cheapest(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack)
	{
		if (stack->cheapest)
			return (stack);
		stack = stack->next;
	}
	return (NULL);
}

// target node = closest smaller node to a in b
// if we can't find the closest smaller node then the target node is max value
t_node	*find_target_node_in_b(t_node *a, t_node *b, int *closest_smallest)
{
	t_node	*current_b;
	t_node	*target;

	current_b = b;
	target = NULL;
	while (current_b)
	{
		if (a->content > current_b->content
			&& current_b->content > *closest_smallest)
		{
			*closest_smallest = current_b->content;
			target = current_b;
		}
		current_b = current_b->next;
	}
	return (target);
}

t_node	*find_target_node_in_a(t_node *b, t_node *a, int *closest_biggest)
{
	t_node	*current_a;
	t_node	*target;

	current_a = a;
	target = NULL;
	while (current_a)
	{
		if (current_a->content > b->content
			&& current_a->content < *closest_biggest)
		{
			*closest_biggest = current_a->content;
			target = current_a;
		}
		current_a = current_a->next;
	}
	return (target);
}
