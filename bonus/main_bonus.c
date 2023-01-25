/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 12:09:41 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/25 10:51:09 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_bloc_1(t_stack_list **stack_a, \
	t_stack_list **stack_b, int argc, char **argv)
{
	int					*tab;
	t_instruction_list	*instruction_lst;

	instruction_lst = NULL;
	tab = ft_generate_tab_int(argc, argv);
	ft_get_index_sorted(stack_a, tab, argc);
	if (ft_check_checker(stack_a, argc) == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
	ft_free_bonus(stack_a, stack_b, instruction_lst, tab);
}

void	ft_affichage(t_stack_list **stack_a, int argc)
{
	if (ft_check_checker(stack_a, argc) == 0)
		ft_printf("KO\n");
	else
		ft_printf("OK\n");
}

int	main(int argc, char **argv)
{
	int					*tab;
	t_instruction_list	*instruction_lst;
	t_stack_list		**stack_a;
	t_stack_list		**stack_b;

	tab = ft_generate_tab_int(argc, argv);
	if (!tab && argc == 1)
		return (0);
	if (!tab)
		return (ft_putstr_fd(ERR_MEMORY_ALLOC, 2), 0);
	instruction_lst = ft_generate_instruction_list(0);
	stack_a = ft_generate_full_stack(tab, argc);
	stack_b = ft_generate_empty_stack(argc);
	if (!instruction_lst && ft_check_error(argc, argv) == 1)
	{	
		free(tab);
		return (ft_bloc_1(stack_a, stack_b, argc, argv), 0);
	}
	if (!instruction_lst || ft_check_instructions(instruction_lst) == 0)
		return (ft_free_bonus(stack_a, stack_b, instruction_lst, tab), 0);
	ft_get_index_sorted(stack_a, tab, argc);
	ft_operation_bonus_rotate(&instruction_lst, stack_a, stack_b);
	ft_affichage(stack_a, argc);
	ft_free_bonus(stack_a, stack_b, instruction_lst, tab);
	return (0);
}
