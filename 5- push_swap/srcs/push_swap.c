/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eleroty <eleroty@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 16:51:19 by eleroty           #+#    #+#             */
/*   Updated: 2024/02/03 14:44:57 by eleroty          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	handle_error_conditions(t_node *a, t_node *tmp)
{
	if (tmp->content > INT_MAX || tmp->content < INT_MIN)
		free_errors(a);
	if (error_duplicate(a, (int)tmp->content))
		free_errors(a);
}

void	stack_add_node(t_node **a, t_node *tmp)
{
	t_node	*end;

	end = ft_last(*a);
	end->next = tmp;
	tmp->prev = end;
}

void	stack_initializor(t_node **a, char **argv)
{
	t_node	*tmp;
	int		i;

	i = 0;
	while (argv[i])
	{
		if (is_error(argv[i]))
			free_errors(*a);
		tmp = malloc(sizeof(t_node));
		if (!tmp)
			return ;
		tmp->next = NULL;
		tmp->content = ft_atol(argv[i]);
		handle_error_conditions(*a, tmp);
		if (!(*a))
		{
			*a = tmp;
			tmp->prev = NULL;
		}
		else
			stack_add_node(a, tmp);
		i++;
	}
}

// void printList(t_node *head)
// {
//     while (head != NULL)
// 	{
//         printf("%ld ", head->content);
//         head = head->next;
//     }
//     printf("\n");
// }

void	cleanup(t_node *a, t_node *b)
{
	free_linked_list(a);
	free_linked_list(b);
}

int	main(int argc, char **argv)
{
	t_node	*a;
	t_node	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (argc == 2 && !argv[1]))
		return (1);
	else if (argc == 2)
	{
		argv = split(argv[1], ' ');
		stack_initializor(&a, argv);
	}
	else
		stack_initializor(&a, argv + 1);
	if (!is_sorted(&a))
	{
		if (ft_size(a) == 2)
			sa(&a);
		else if (ft_size(a) == 3)
			sort_3(&a);
		else
			sort(&a, &b);
	}
	cleanup(a, b);
	return (0);
}
