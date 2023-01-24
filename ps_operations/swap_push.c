/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_push.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 09:53:56 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/24 17:24:59 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Swap and Push rules */

#include "../pushswap.h"

/* inversion du premier et du second element de la pile */

void	ft_swap_a(t_stack_list **stack, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*first;
	t_stack_list	*second;
	char			*instruction;

	if (!*stack || (*stack)->index_sorted == 0)
		return ;
	first = *stack;
	if (!(*stack)->next || (*stack)->next->index_sorted == 0)
		return ;
	instruction = ft_calloc(sizeof(char), 3);
	if (!instruction)
		return ;
	second = first->next;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = 0;
	*stack = second;
	instruction[0] = 's';
	instruction[1] = 'a';
	ft_add_instruction_to_list(instruction_list, instruction);
}

void	ft_swap_b(t_stack_list **stack, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*first;
	t_stack_list	*second;
	char			*instruction;

	if (!*stack || (*stack)->index_sorted == 0)
		return ;
	first = *stack;
	if (!(*stack)->next || (*stack)->next->index_sorted == 0)
		return ;
	instruction = ft_calloc(sizeof(char), 3);
	if (!instruction)
		return ;
	second = first->next;
	first->next = second->next;
	first->previous = second;
	second->next = first;
	second->previous = 0;
	*stack = second;
	instruction[0] = 's';
	instruction[1] = 'b';
	ft_add_instruction_to_list(instruction_list, instruction);
}

void	ft_double_swap(t_stack_list **stack1, t_stack_list **stack2, \
	t_instruction_list **instruction_list)
{
	ft_swap_a(stack1, instruction_list);
	ft_swap_b(stack2, instruction_list);
}

/* premier element de 1 vers haut de la pile 2 */

void	ft_push_a_to_b(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*elem_top;
	char			*instruction;

	if (!*stack_a || (*stack_a)->index_sorted == 0)
		return ;
	instruction = ft_calloc(sizeof(char), 3);
	if (!instruction)
		return ;
	elem_top = ft_pop_first(stack_a);
	ft_add_first(stack_b, elem_top);
	instruction[0] = 'p';
	instruction[1] = 'b';
	ft_add_instruction_to_list(instruction_list, instruction);
}

void	ft_push_b_to_a(t_stack_list **stack_b, t_stack_list **stack_a, \
	t_instruction_list **instruction_list)
{
	t_stack_list	*elem_top;
	char			*instruction;

	if (!*stack_b || (*stack_b)->index_sorted == 0)
		return ;
	instruction = ft_calloc(sizeof(char), 3);
	if (!instruction)
		return ;
	elem_top = ft_pop_first(stack_b);
	ft_add_first(stack_a, elem_top);
	instruction[0] = 'p';
	instruction[1] = 'a';
	ft_add_instruction_to_list(instruction_list, instruction);
}
