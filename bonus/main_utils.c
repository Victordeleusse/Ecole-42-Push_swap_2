/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 17:42:26 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/24 19:41:23 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_check_checker(t_stack_list **stack_a, int argc)
{
	int					count;
	t_stack_list		*begin_a;

	if (!(*stack_a) || (*stack_a)->index_sorted == 0)
		return (0);
	begin_a = *stack_a;
	count = 0;
	if (begin_a->index_sorted != 1)
		return (0);
	while (begin_a->next)
	{
		if (begin_a->index_sorted != begin_a->next->index_sorted - 1 && \
			begin_a->next->index_sorted != 0)
			return (0);
		begin_a = begin_a->next;
		count++;
	}
	if ((begin_a->index_sorted != argc - 1 || count != argc - 2) && \
		begin_a->index_sorted != 0)
		return (0);
	return (1);
}

char	**ft_generate_instruction_tab_bis(void)
{
	char	**instruction_tab;

	instruction_tab = ft_calloc(sizeof(char *), 12);
	if (!instruction_tab)
		return (NULL);
	instruction_tab[0] = ft_give_instruction('r', 'a', '\0');
	instruction_tab[1] = ft_give_instruction('r', 'b', '\0');
	instruction_tab[2] = ft_give_instruction('r', 'r', '\0');
	instruction_tab[3] = ft_give_instruction('s', 'a', '\0');
	instruction_tab[4] = ft_give_instruction('s', 'b', '\0');
	instruction_tab[5] = ft_give_instruction('s', 's', '\0');
	instruction_tab[6] = ft_give_instruction('r', 'r', 'a');
	instruction_tab[7] = ft_give_instruction('r', 'r', 'b');
	instruction_tab[8] = ft_give_instruction('r', 'r', 'r');
	instruction_tab[9] = ft_give_instruction('p', 'a', '\0');
	instruction_tab[10] = ft_give_instruction('p', 'b', '\0');
	instruction_tab[11] = 0;
	return (instruction_tab);
}

int	ft_check_instructions(t_instruction_list *instruction_lst)
{
	t_instruction_list	*begin;
	char				**instruction_tab;

	instruction_tab = ft_generate_instruction_tab_bis();
	begin = instruction_lst;
	if (ft_first_order_is_available(instruction_tab, begin->instruction) == 0)
	{
		ft_free_instruction_tab(instruction_tab);
		return (ft_putstr_fd(ERR_WRONGENTRY, 2), 0);
	}
	while (begin->next)
		begin = begin->next;
	if (ft_first_order_is_available(instruction_tab, \
		begin->instruction) == 0 && \
		ft_first_order_is_available(instruction_tab, begin->instruction) == 0)
	{	
		ft_free_instruction_tab(instruction_tab);
		return (ft_putstr_fd(ERR_WRONGENTRY, 2), 0);
	}
	ft_free_instruction_tab(instruction_tab);
	return (1);
}
