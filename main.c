/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 16:15:27 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/19 19:37:42 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_opti_display(t_instruction_list *instruction_list)
{
	t_instruction_list	*begin_list;

	ft_opti_swap(&instruction_list);
	ft_opti_rotate(&instruction_list);
	ft_opti_reverse_rotate(&instruction_list);
	begin_list = instruction_list;
	begin_list = begin_list->next;
	while (begin_list)
	{
		ft_printf("%s\n", begin_list->instruction);
		begin_list = begin_list->next;
	}
}

void	ft_operation(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list *instruction_list, int argc)
{
	t_stack_list	*begin_a;
	// t_stack_list	*begin_b;

	if (argc - 1 <= 5)
		ft_sort_5(stack_a, stack_b, &instruction_list);
	else if (argc - 1 <= 10)
	{
		ft_separate_stack(stack_a, stack_b, argc - 1, &instruction_list);
		ft_sort_5(stack_a, stack_b, &instruction_list);
		ft_restore_b_to_a(stack_b, stack_a, &instruction_list);
	}
	else if (argc - 1 <= 100)
	{
		ft_send_from_a_to_b(stack_a, stack_b, &instruction_list);
		// begin_a = *stack_a;
		// printf("\nSTACK A INITIALEMENT TRIE\n");
		// while(begin_a)
		// {
		// 	printf("indice : %d\n", begin_a->index_sorted);
		// 	begin_a = begin_a->next;
		// }
		// printf("\n");
		while (*stack_b)
		{
			ft_calculate_distance_to_sort(stack_a, stack_b);
			ft_send_elem_from_b_to_a(stack_a, stack_b, &instruction_list);
		}
		ft_finish_to_ordonate(stack_a, &instruction_list);
		// begin_a = *stack_a;
		// printf("\n\nSTACK A\n");
		// while(begin_a)
		// {
		// 	printf("indice : %d\n", begin_a->index_sorted);
		// 	begin_a = begin_a->next;
		// }
	}
}

int	main(int argc, char **argv)
{
	int					*tab;
	t_stack_list		**stack_a;
	t_stack_list		**stack_b;
	t_instruction_list	*instruction_list;

	tab = ft_generate_tab_int(argc, argv);
	if (tab == NULL)
		return (0);
	stack_a = ft_generate_full_stack(tab, argc);
	stack_b = ft_generate_empty_stack(argc);
	if (!stack_a || !stack_b)
		return (0);
	ft_get_index_sorted(stack_a, tab, argc);
	instruction_list = ft_generate_instruction_element("1");
	if (!instruction_list)
		return (0);
	ft_operation(stack_a, stack_b, instruction_list, argc);
	ft_opti_display(instruction_list);
	// ft_free(stack_a, stack_b, instruction_list, tab);
	return (0);
}
