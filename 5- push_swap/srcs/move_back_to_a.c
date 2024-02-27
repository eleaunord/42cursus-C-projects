/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_back_to_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:08:48 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/31 16:18:15 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	setting_and_analysis_b_to_a(t_node *a, t_node *b)
{
	set_index(a);
	set_index(b);
	set_target_b_to_a(a, b);
}

void	check(t_node **stack, t_node *top_node)
{
	while (*stack != top_node && top_node != NULL)
	{
		if (!stack)
			break ;
		if (top_node->first_half)
			ra(stack);
		else
			rra(stack);
	}
}
