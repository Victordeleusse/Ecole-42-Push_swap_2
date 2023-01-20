/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_already_sort_list.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 19:56:22 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/20 16:51:40 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_init_already_sort_below(t_stack_list **stack_a)
{
	t_stack_list	*heaviest;
	t_stack_list	*is_lighter;

	heaviest = ft_get_heaviest_elem(stack_a);
	is_lighter = heaviest->next;
	if (!is_lighter)
		return ;
	while (is_lighter)
	{
		if (is_lighter->exit_weight == (heaviest->exit_weight - 1) \
			&& is_lighter->index_sorted > heaviest->index_sorted)
		{
			is_lighter->is_already_sort = 1;
			heaviest = is_lighter;
		}
		is_lighter = is_lighter->next;
	}
}

int	ft_get_biggest_index_below_heaviest(t_stack_list **stack_a)
{
	t_stack_list	*heaviest;
	t_stack_list	*lighter;
	t_stack_list	*max_sorted;
	int				max_index_sorted;

	heaviest = ft_get_heaviest_elem(stack_a);
	max_sorted = heaviest;
	lighter = heaviest->next;
	while (lighter)
	{
		if (lighter->is_already_sort == 1)
			max_sorted = lighter;
		lighter = lighter->next;
	}
	return (max_sorted->index_sorted);
}

void	ft_init_already_sort_above(t_stack_list **stack_a)
{
	t_stack_list	*heaviest;
	t_stack_list	*is_lighter;
	int				max_index_sorted_above;
	int				light_weight;

	heaviest = ft_get_heaviest_elem(stack_a);
	max_index_sorted_above = ft_get_biggest_index_below_heaviest(stack_a);
	is_lighter = heaviest->previous;
	light_weight = 1;
	if (!is_lighter)
		return ;
	while (is_lighter)
	{
		if (is_lighter->exit_weight == light_weight \
			&& is_lighter->index_sorted > max_index_sorted_above)
		{	
			is_lighter->is_already_sort = 1;
			light_weight++;
		}
		is_lighter = is_lighter->previous;
	}
}

void	ft_kick_from_a(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list **instruction_list, int distance)
{
	int				index_mediane;

	index_mediane = ft_get_mediane_index(stack_a);
	while (distance)
	{
		ft_rotate_a(stack_a, instruction_list);
		distance--;
	}
	ft_push_a_to_b(stack_a, stack_b, instruction_list);
	if ((*stack_b)->index_sorted > index_mediane)
		ft_rotate_b(stack_b, instruction_list);
}

void	ft_send_from_a_to_b(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	int				distance;
	t_stack_list	*begin_a;

	ft_init_exit_weight(stack_a);
	ft_init_already_sort_below(stack_a);
	ft_init_already_sort_above(stack_a);
	begin_a = *stack_a;
	distance = 0;
	while (begin_a)
	{
		if (begin_a->is_already_sort == 1)
		{
			begin_a = begin_a->next;
			distance++;
		}
		else
		{
			ft_kick_from_a(stack_a, stack_b, instruction_list, distance);
			begin_a = *stack_a;
			distance = 0;
		}
	}
}
