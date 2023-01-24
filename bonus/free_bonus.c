/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 11:21:36 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/24 19:47:49 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	ft_free_instruction_tab(char **tab)
{
	int	i;

	if (!tab)
		return ;
	i = 0;
	while (tab[i])
	{
		free (tab[i]);
		i++;
	}
	free(tab);
}

void	ft_free_bonus(t_stack_list **stack_a, t_stack_list **stack_b, \
	t_instruction_list *instruction_list, int *tab)
{
	if (instruction_list)
	{	
		ft_free_instruction_list(instruction_list->next);
		free(instruction_list->instruction);
		free(instruction_list);
	}
	if (stack_a)
		ft_free_stack(stack_a);
	if (stack_b)
		ft_free_stack(stack_b);
	if (tab)
		free(tab);
}

int	ft_check_error(int argc, char **argv)
{
	int	i;

	i = 1;
	while (argv[i])
	{
		if ('0' <= argv[i][0] && argv[i][0] <= '9')
			i++;
		else if ((argv[i][0] == '+' || argv[i][0] == '-') \
				&& '0' <= argv[i][1] && argv[i][1] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}
