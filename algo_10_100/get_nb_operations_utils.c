/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_operations_utils.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:10:09 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/20 17:18:07 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_case_max_in_a(t_stack_list **stack_a, t_stack_list *target, \
	int index_max_a)
{
	t_stack_list	*begin_a;
	int				distance;
	int				size_stack_a;

	begin_a = *stack_a;
	size_stack_a = ft_get_stack_size(stack_a);
	distance = 0;
	while (begin_a && begin_a->index_sorted != index_max_a)
	{
		begin_a = begin_a->next;
		distance++;
	}
	if (distance == size_stack_a)
		return (0);
	else if (distance <= size_stack_a / 2)
		return (distance);
	else
		return (size_stack_a - distance);
}

int	ft_case_min_in_a(t_stack_list **stack_a, t_stack_list *target, \
	int index_min_a)
{
	t_stack_list	*begin_a;
	int				distance;
	int				size_stack_a;

	begin_a = *stack_a;
	size_stack_a = ft_get_stack_size(stack_a);
	distance = 0;
	while (begin_a && begin_a->index_sorted != index_min_a)
	{
		begin_a = begin_a->next;
		distance++;
	}
	if (distance == size_stack_a)
		return (0);
	else if (distance <= size_stack_a / 2)
		return (distance);
	else
		return (size_stack_a - distance);
}

int	ft_case_regular_in_a(t_stack_list **stack_a, t_stack_list *target)
{
	t_stack_list	*begin_a;
	int				distance;
	int				size_stack_a;

	begin_a = *stack_a;
	size_stack_a = ft_get_stack_size(stack_a);
	distance = 1;
	while (begin_a->next)
	{	
		if (begin_a->index_sorted < target->index_sorted \
			&& begin_a->next->index_sorted > target->index_sorted)
		{
			if (distance <= size_stack_a / 2)
				return (distance);
			else
				return (size_stack_a - distance);
		}	
		begin_a = begin_a->next;
		distance++;
	}	
}
