/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pos_in_a_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 11:45:15 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/20 11:45:44 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_case_max_in_stack(t_stack_list **stack_a, t_stack_list *target, \
			int index_max_a, int size_stack_a)
{
	t_stack_list	*begin_a;
	int				distance;

	distance = 0;
	begin_a = *stack_a;
	while (begin_a && begin_a->index_sorted != index_max_a)
	{
		begin_a = begin_a->next;
		distance++;
	}
	if (distance == size_stack_a)
		return (0);
	return (distance + 1);
}

int	ft_case_min_in_stack(t_stack_list **stack_a, t_stack_list *target, \
			int index_min_a, int size_stack_a)
{
	t_stack_list	*begin_a;
	int				distance;

	distance = 0;
	begin_a = *stack_a;
	while (begin_a && begin_a->index_sorted != index_min_a)
	{
		begin_a = begin_a->next;
		distance++;
	}
	if (distance == size_stack_a)
		return (0);
	return (distance);
}

int	ft_case_standard(t_stack_list **stack_a, t_stack_list *target)
{
	t_stack_list	*begin_a;
	int				distance;

	distance = 1;
	begin_a = *stack_a;
	while (begin_a->next)
	{	
		if (begin_a->index_sorted < target->index_sorted \
			&& begin_a->next->index_sorted > target->index_sorted)
			return (distance);
		begin_a = begin_a->next;
		distance++;
	}
}
