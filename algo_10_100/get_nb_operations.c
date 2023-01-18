/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_nb_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:12:45 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/18 14:46:54 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

// la fonction ft_get_stack_size existe -> algo_5_10

int	ft_get_on_top_of_b(t_stack_list **stack_b, t_stack_list *target)
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

