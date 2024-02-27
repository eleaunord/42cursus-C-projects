/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:52:01 by eleroty           #+#    #+#             */
/*   Updated: 2024/02/03 14:52:01 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// here we look how we can put b in descending order the cheapest way
/*
x operations to bring a on top stack a
+ x operations to bring a->target node on top b
= push_cost
*/
void	cost_analysis(t_node *a, t_node *b)
{
	int	size_a;
	int	size_b;

	size_a = ft_size(a);
	size_b = ft_size(b);
	while (a)
	{
		a->push_cost = a->index;
		if (!(a->first_half))
			a->push_cost = size_a - (a->index);
		if (a->target_node->first_half)
			a->push_cost += a->target_node->index;
		else
			a->push_cost += size_b - (a->target_node->index);
		a = a->next;
	}
}

void	rotate_cheapest(t_node **a, t_node **b, t_node *cheapest_node, int move)
{
	if (move == 3)
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rrr(a, b);
	}
	else
	{
		while (*b != cheapest_node->target_node && *a != cheapest_node)
			rr(a, b);
	}
}

void	before_push(t_node **stack, t_node *top_node, char stack_name)
{
	while (*stack != top_node)
	{
		if (!stack)
			break ;
		if (stack_name == 'a')
		{
			if (top_node->first_half)
				ra(stack);
			else
				rra(stack);
		}
		else if (stack_name == 'b')
		{
			if (top_node->first_half)
				rb(stack);
			else
				rrb(stack);
		}
	}
}

/*
function that moves min to the top
*/
static void	min_top_stack(t_node **a)
{
	t_min_values	min_values;
	t_node			*min_node;

	min_values = find_min(*a);
	min_node = find_content_node(a, min_values.min);
	while ((*a)->content != min_node->content)
	{
		if (min_node->first_half)
			ra(a);
		else
			rra(a);
	}
}

void	sort(t_node **a, t_node **b)
{
	int	size_a;
	int	size_b;

	size_a = ft_size(*a);
	size_b = ft_size(*b);
	push_elements_to_b(a, b);
	while (size_a-- > 3 && !is_sorted(a))
	{
		setting_and_analysis_a_to_b(*a, *b);
		push_a_to_b(a, b);
	}
	sort_3(a);
	while (*b)
	{
		setting_and_analysis_b_to_a(*a, *b);
		check(a, (*b)->target_node);
		pa(a, b);
	}
	set_index(*a);
	min_top_stack(a);
}
