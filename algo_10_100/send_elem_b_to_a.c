/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_elem_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:05:53 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/20 12:23:31 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack_list	*ft_get_elem_to_send(t_stack_list **stack_b)
{
	t_stack_list	*begin_b;
	t_stack_list	*elem_opti;

	elem_opti = *stack_b;
	begin_b = (*stack_b)->next;
	while (begin_b)
	{
		if (begin_b->distance_to_sort < elem_opti->distance_to_sort)
			elem_opti = begin_b;
		begin_b = begin_b->next;
	}
	return (elem_opti);
}

int	ft_get_position_in_b(t_stack_list **stack_b, t_stack_list *elem)
{
	t_stack_list	*begin_b;
	int				position;

	begin_b = *stack_b;
	position = 1;
	while (begin_b && begin_b->index_sorted != elem->index_sorted)
	{
		position++;
		begin_b = begin_b->next;
	}
	return (position);
}

int	ft_get_position_in_a(t_stack_list **stack_a, t_stack_list *target)
{
	t_stack_list	*begin_a;
	t_stack_list	*last_a;
	int				index_max_a;
	int				index_min_a;
	int				size_stack_a;

	index_max_a = ft_get_index_max(stack_a);
	index_min_a = ft_get_index_min(stack_a);
	size_stack_a = ft_get_stack_size(stack_a);
	begin_a = *stack_a;
	last_a = ft_get_last_stack(stack_a);
	if (target->index_sorted > index_max_a)
		return (ft_case_max_in_stack(stack_a, target, index_max_a, \
			size_stack_a));
	else if (target->index_sorted < index_min_a)
		return (ft_case_min_in_stack(stack_a, target, index_min_a, \
			size_stack_a));
	else if (target->index_sorted < begin_a->index_sorted && \
		target->index_sorted > last_a->index_sorted)
		return (0);
	else
		return (ft_case_standard(stack_a, target));
}

void	ft_send_elem_from_b_to_a(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	t_stack_list	*elem_opti;
	int				position_in_a;
	int				size_stack_a;

	elem_opti = ft_get_elem_to_send(stack_b);
	size_stack_a = ft_get_stack_size(stack_a);
	position_in_a = ft_get_position_in_a(stack_a, elem_opti);
	ft_prepare_stack_b(stack_b, instruction_list, elem_opti);
	ft_prepare_stack_a(stack_a, instruction_list, elem_opti);
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}
