/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:38:16 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/24 17:38:45 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_operation_bonus_rev(t_instruction_list *begin, \
	t_instruction_list *instruction_lst_annexe, \
	t_stack_list **stack_a, t_stack_list **stack_b)
{
	if (begin->instruction[0] == 'r' && begin->instruction[1] == 'r' \
		&& begin->instruction[2] == 'a')
		ft_reverse_rotate_a(stack_a, &instruction_lst_annexe);
	else if (begin->instruction[0] == 'r' && begin->instruction[1] == 'r' \
		&& begin->instruction[2] == 'b')
		ft_reverse_rotate_b(stack_b, &instruction_lst_annexe);
	else if (begin->instruction[0] == 'r' && begin->instruction[1] == 'r' \
		&& begin->instruction[2] == 'r')
	{
		ft_reverse_rotate_a(stack_a, &instruction_lst_annexe);
		ft_reverse_rotate_b(stack_b, &instruction_lst_annexe);
	}
}

void	ft_operation_bonus_swap_push_rev(t_instruction_list *begin, \
	t_instruction_list *instruction_lst_annexe, \
	t_stack_list **stack_a, t_stack_list **stack_b)
{
	if (begin->instruction[0] == 's' && begin->instruction[1] == 'a')
		ft_swap_a(stack_a, &instruction_lst_annexe);
	else if (begin->instruction[0] == 's' && begin->instruction[1] == 'b')
		ft_swap_b(stack_b, &instruction_lst_annexe);
	else if (begin->instruction[0] == 's' && begin->instruction[1] == 's')
	{	
		ft_swap_a(stack_a, &instruction_lst_annexe);
		ft_swap_b(stack_b, &instruction_lst_annexe);
	}
	else if (begin->instruction[0] == 'p' && begin->instruction[1] == 'a')
		ft_push_b_to_a(stack_b, stack_a, &instruction_lst_annexe);
	else if (begin->instruction[0] == 'p' && begin->instruction[1] == 'b')
		ft_push_a_to_b(stack_a, stack_b, &instruction_lst_annexe);
	else if (begin->instruction[0] == 'r' && begin->instruction[1] == 'b')
		ft_rotate_b(stack_b, &instruction_lst_annexe);
	else
		ft_operation_bonus_rev(begin, instruction_lst_annexe, \
				stack_a, stack_b);
}

void	ft_operation_bonus_rotate(t_instruction_list **instruction_lst, \
	t_stack_list **stack_a, t_stack_list **stack_b)
{
	t_instruction_list	*instruction_lst_annexe;
	t_instruction_list	*begin;

	begin = *instruction_lst;
	instruction_lst_annexe = ft_generate_instruction_element("1");
	if (!instruction_lst_annexe)
		return ;
	while (begin)
	{
		if (begin->instruction[0] == 'r' && begin->instruction[1] == 'a')
			ft_rotate_a(stack_a, &instruction_lst_annexe);
		else if (begin->instruction[0] == 'r' && begin->instruction[1] == 'r' \
			&& begin->instruction[2] == '\0')
		{
			ft_rotate_a(stack_a, &instruction_lst_annexe);
			ft_rotate_b(stack_b, &instruction_lst_annexe);
		}
		else
			ft_operation_bonus_swap_push_rev(begin, instruction_lst_annexe, \
				stack_a, stack_b);
		begin = begin->next;
	}
	ft_free_instruction_list(instruction_lst_annexe->next);
	free(instruction_lst_annexe);
}
