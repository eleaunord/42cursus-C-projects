/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_to_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:08:50 by eleroty           #+#    #+#             */
/*   Updated: 2024/02/03 14:51:24 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push_elements_to_b(t_node **a, t_node **b)
{
	int	size_a;
	int	num_in_b;

	size_a = ft_size(*a);
	num_in_b = 0;
	while (size_a-- > 3 && !is_sorted(a) && num_in_b++ <= 2)
	{
		pb(b, a);
		if (size_a <= 3 || is_sorted(a) || num_in_b > 2)
			break ;
	}
}

void	setting_and_analysis_a_to_b(t_node *a, t_node *b)
{
	set_index(a);
	set_index(b);
	set_target_a_to_b(a, b);
	cost_analysis(a, b);
	set_cheapest(a);
}

/*
pushing the cheapest_node to sorted b
cheapest above target node and on top
1. making sure the one at the top are not the cheapest nodes
2. refresh current node positions
3. making sure if cheapest of a at top of a and cheapest's target at top of b
4. ensure the cheapest nodes is at the top, ready for pushing
5. ensure the target node is at the top, ready for pushing
6. finally pushing a to b
*/
void	push_a_to_b(t_node **a, t_node **b)
{
	t_node	*cheapest_node;

	cheapest_node = get_cheapest(*a);
	if (!(cheapest_node->first_half)
		&& !(cheapest_node->target_node->first_half))
		rotate_cheapest(a, b, cheapest_node, 3);
	else if (cheapest_node->first_half
		&& cheapest_node->target_node->first_half)
		rotate_cheapest(a, b, cheapest_node, 2);
	set_index(*a);
	set_index(*b);
	before_push(a, cheapest_node, 'a');
	before_push(b, cheapest_node->target_node, 'b');
	pb(b, a);
}
