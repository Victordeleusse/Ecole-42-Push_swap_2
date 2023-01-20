/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prepare_stack_before_push_utils.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 12:04:24 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/20 12:22:17 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_prepare_stack_b(t_stack_list **stack_b, \
	t_instruction_list **instruction_list, t_stack_list *elem_opti)
{
	int	position_in_b;
	int	size_stack_b;

	size_stack_b = ft_get_stack_size(stack_b);
	position_in_b = ft_get_position_in_b(stack_b, elem_opti);
	if (position_in_b <= size_stack_b / 2)
	{
		while ((*stack_b)->index_sorted != elem_opti->index_sorted)
			ft_rotate_b(stack_b, instruction_list);
	}
	else
	{
		while ((*stack_b)->index_sorted != elem_opti->index_sorted)
			ft_reverse_rotate_b(stack_b, instruction_list);
	}	
}

void	ft_prepare_stack_a(t_stack_list **stack_a, \
	t_instruction_list **instruction_list, t_stack_list *elem_opti)
{
	int	position_in_a;
	int	size_stack_a;

	size_stack_a = ft_get_stack_size(stack_a);
	position_in_a = ft_get_position_in_a(stack_a, elem_opti);
	if (position_in_a <= size_stack_a / 2)
	{
		while (position_in_a)
		{	
			ft_rotate_a(stack_a, instruction_list);
			position_in_a--;
		}
	}
	else
	{
		position_in_a = size_stack_a - (position_in_a);
		while (position_in_a)
		{
			ft_reverse_rotate_a(stack_a, instruction_list);
			position_in_a--;
		}
	}
}
