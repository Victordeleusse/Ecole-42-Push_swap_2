/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_elem_b_to_a.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:05:53 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/19 19:06:12 by vde-leus         ###   ########.fr       */
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
	// if (elem_opti->index_sorted == 99)
	// 	printf("Indice opti a envoyer : %d\n", elem_opti->index_sorted);
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
	// if (elem->index_sorted == 99)
	// 	printf("position dans B : %d\n", position);
	return (position);
}

int	ft_get_position_in_a(t_stack_list **stack_a, t_stack_list *target)
{
	t_stack_list	*begin_a;
	t_stack_list	*last_a;
	int				index_max_a;
	int				index_min_a;
	int				distance;
	int				size_stack_a;

	index_max_a = ft_get_index_max(stack_a);
	index_min_a = ft_get_index_min(stack_a);
	distance = 0;
	size_stack_a = ft_get_stack_size(stack_a);
	begin_a = *stack_a;
	last_a = ft_get_last_stack(stack_a);
	if (target->index_sorted > index_max_a)
	{
		while (begin_a && begin_a->index_sorted != index_max_a)
		{
			begin_a = begin_a->next;
			distance++;
		}
		// if (target->index_sorted == 99)
		// {	
		// 	printf("distance dans A si on envoie le maximum : %d\n", distance);
		// 	printf("\n\n");
		// 	begin_a = *stack_a;
		// 	while (begin_a)
		// 	{
		// 		printf("indice : %d\n", begin_a->index_sorted);
		// 		begin_a = begin_a->next;
		// 	}
		// }
		if (distance == size_stack_a)
			return (0);
		return (distance + 1);
	}
	else if (target->index_sorted < index_min_a)
	{
		while (begin_a && begin_a->index_sorted != index_min_a)
		{
			begin_a = begin_a->next;
			distance++;
		}
		// if (target->index_sorted == 99)
			// printf("distance dans A si on envoie le minimum : %d\n", distance);
		if (distance == size_stack_a)
			return (0);
		return (distance);
	}
	else if (target->index_sorted < begin_a->index_sorted && target->index_sorted > last_a->index_sorted)
	{	
		// if (target->index_sorted == 99)
			// printf("Cas ou on est inf au top et sup au dernier de A : %d vs au top : %d a la fin : %d\n", target->index_sorted, begin_a->index_sorted, last_a->index_sorted);
		return (0);
	}
	else
	{
		distance = 1;
		while (begin_a->next)
		{	
			if (begin_a->index_sorted < target->index_sorted \
				&& begin_a->next->index_sorted > target->index_sorted)
			{	
				// if (target->index_sorted == 99)
					// printf("A intercaler entre %d et %d -> distance de %d\n", begin_a->index_sorted, begin_a->next->index_sorted, distance);
				return (distance);
			}
			begin_a = begin_a->next;
			distance++;
			// if (target->index_sorted == 99)
				// printf("Indice : %d et distance dans A : %d\n", target->index_sorted, distance);
		}	
	}
}

void	ft_send_elem_from_b_to_a(t_stack_list **stack_a, \
	t_stack_list **stack_b, t_instruction_list **instruction_list)
{
	t_stack_list	*elem_opti;
	int				position_in_b;
	int				position_in_a;
	int				size_stack_a;
	int				size_stack_b;
	int				index_max;
	
	index_max = ft_get_index_max(stack_b);
	elem_opti = ft_get_elem_to_send(stack_b);
	size_stack_a = ft_get_stack_size(stack_a);
	size_stack_b = ft_get_stack_size(stack_b);
	position_in_b = ft_get_position_in_b(stack_b, elem_opti);
	position_in_a = ft_get_position_in_a(stack_a, elem_opti);
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
	if (position_in_a <= size_stack_a / 2)
	{
		while (position_in_a)
		{	
			// if (elem_opti->index_sorted == 99)
			// 	printf("Rotate -> position dans A ? %d\n", position_in_a);
			ft_rotate_a(stack_a, instruction_list);
			position_in_a--;
		}
	}
	else 
	{
		position_in_a = size_stack_a - (position_in_a);
		while (position_in_a)
		{
			// if (elem_opti->index_sorted == 99)
			// 	printf("Reverse rotate -> position dans A ? %d\n", position_in_a);
			ft_reverse_rotate_a(stack_a, instruction_list);
			position_in_a--;
		}
	}
	ft_push_b_to_a(stack_b, stack_a, instruction_list);
}