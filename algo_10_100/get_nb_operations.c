/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:12:45 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/20 17:15:24 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// la fonction ft_get_stack_size existe -> algo_5_10
// les fonctions ft_get_index min & max -> utils_v3

int	ft_distance_to_get_on_top_of_b(t_stack_list **stack_b, t_stack_list *target)
{
	t_stack_list	*begin;
	int				size_stack_b;
	int				distance;

	begin = *stack_b;
	size_stack_b = ft_get_stack_size(stack_b);
	distance = 0;
	while (begin && begin->index_sorted != target->index_sorted)
	{
		begin = begin->next;
		distance++;
	}
	if (distance > (size_stack_b / 2))
		return (size_stack_b - distance);
	return (distance);
}

int	ft_distance_to_put_in_a_from_top_b(t_stack_list **stack_a, \
	t_stack_list *target)
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
		return (ft_case_max_in_a(stack_a, target, index_max_a));
	else if (target->index_sorted < index_min_a)
		return (ft_case_min_in_a(stack_a, target, index_min_a));
	else if (target->index_sorted < begin_a->index_sorted && \
			target->index_sorted > last_a->index_sorted)
		return (0);
	else
		return (ft_case_regular_in_a(stack_a, target));
}

void	ft_calculate_distance_to_sort(t_stack_list **stack_a, \
	t_stack_list **stack_b)
{
	t_stack_list	*begin_b;
	int				distance_top_b;
	int				distance_in_a;

	begin_b = *stack_b;
	while (begin_b)
	{
		distance_top_b = ft_distance_to_get_on_top_of_b(stack_b, begin_b);
		distance_in_a = ft_distance_to_put_in_a_from_top_b(stack_a, begin_b);
		begin_b->distance_to_sort = distance_top_b + distance_in_a;
		begin_b = begin_b->next;
	}
}
