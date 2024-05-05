/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 18:40:46 by eleroty           #+#    #+#             */
/*   Updated: 2023/11/20 18:41:29 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*node;

	node = malloc(sizeof(t_list));
	if (node == NULL)
		return (NULL);
	node->content = content;
	node->next = NULL;
	return (node);
}

// int main (void)
// {
//     t_node  *root;

//     root = malloc(sizeof(t_node));
//     root ->next = malloc(sizeof(t_node));
//     root ->next ->next = malloc(sizeof(t_node));

//     root ->n = 43;
//     root ->next ->n = 123;
//     root ->next ->next ->n = 32;
//     root ->next ->next ->next = 322;

//     t_node  *current;

//     current = root;
//     while (current)
//     {
//         printf("%d", current->n);
//         current = current->next;
//     }
// }
