/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ordonate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:16:27 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/20 12:25:52 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_finish_to_ordonate(t_stack_list **stack_a, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*begin_a;
	int				index_mini_a;
	int				distance;
	int				size_stack_a;

	index_mini_a = ft_get_index_min(stack_a);
	begin_a = *stack_a;
	distance = 0;
	size_stack_a = ft_get_stack_size(stack_a);
	while (begin_a && begin_a->index_sorted == index_mini_a)
	{
		distance++;
		begin_a = begin_a->next;
	}
	if (distance <= size_stack_a / 2)
	{
		while ((*stack_a)->index_sorted != index_mini_a)
			ft_rotate_a(stack_a, instruction_list);
	}
	else
	{
		while ((*stack_a)->index_sorted != index_mini_a)
			ft_reverse_rotate_a(stack_a, instruction_list);
	}
}
