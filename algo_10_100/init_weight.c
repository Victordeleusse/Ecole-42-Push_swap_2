/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_weight.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:31:21 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/17 20:08:40 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_stack_list	*ft_get_last_stack(t_stack_list **stack_a)
{
	t_stack_list	*last;
	
	last = *stack_a;
	while(last->next)
		last = last->next;
	return(last);	
}

void	ft_exit_weight_per_elem(t_stack_list *element)
{
	t_stack_list	*begin;
	
	begin = element->next;
	while(begin)
	{
		if (element->index_sorted < begin->index_sorted \
			&& element->exit_weight <= begin->exit_weight)
			element->exit_weight = begin->exit_weight + 1;
		begin = begin->next;
	}
}

void	ft_init_exit_weight(t_stack_list **stack_a)
{
	t_stack_list	*last;
	t_stack_list	*prev;

	last = ft_get_last_stack(stack_a);
	last->exit_weight = 1;
	prev = last->previous;
	while(prev)
	{
		ft_exit_weight_per_elem(prev);
		prev = prev->previous;
	}
}

t_stack_list	*ft_get_heaviest_elem(t_stack_list **stack_a)
{
	t_stack_list	*begin_a;
	t_stack_list	*heaviest;

	begin_a = *stack_a;
	heaviest = *stack_a;
	while(begin_a)
	{
		if (begin_a->exit_weight > heaviest->exit_weight)
			heaviest = begin_a;
		begin_a = begin_a->next;
	}
	heaviest->is_already_sort = 1;
	return (heaviest);
}
