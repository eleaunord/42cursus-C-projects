/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 16:25:04 by eleroty           #+#    #+#             */
/*   Updated: 2024/01/31 16:25:55 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_size(t_node *lst)
{
	int	counter;

	counter = 0;
	while (lst != NULL)
	{
		++counter;
		lst = lst->next;
	}
	return (counter);
}

void	ft_add_front(t_node **lst, t_node *new)
{
	if (lst && new)
	{
		new->next = *lst;
		*lst = new;
	}
}

t_node	*ft_last(t_node *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
	{
		lst = lst->next;
	}
	return (lst);
}
