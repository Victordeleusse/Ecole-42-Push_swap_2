/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:22:59 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/25 10:40:28 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

t_instruction_list	*ft_generate_instruction_bloc(char **instruction_tab, \
		char *order)
{
	t_instruction_list	*instruction_bloc;
	size_t				len_order;
	size_t				i;

	instruction_bloc = ft_calloc(sizeof(t_instruction_list), 1);
	if (!instruction_bloc)
		return (NULL);
	instruction_bloc->instruction = ft_calloc(sizeof(order), 1);
	len_order = ft_strlen(order);
	i = 0;
	while (i < len_order)
	{
		instruction_bloc->instruction[i] = order[i];
		i++;
	}
	instruction_bloc->instruction[len_order - 1] = '\0';
	instruction_bloc->next = 0;
	free(order);
	return (instruction_bloc);
}

void	ft_generate_the_list(int fd, t_instruction_list	**begin, \
	char **instruction_tab)
{
	t_instruction_list	*next_bloc;
	char				*order;

	while (1)
	{
		order = get_next_line(fd);
		if (order == NULL)
			break ;
		else if (ft_order_is_available(instruction_tab, order) == 0)
		{
			next_bloc = ft_generate_instruction_bloc(instruction_tab, order);
			(*begin)->next = next_bloc;
			(*begin) = next_bloc;
			break ;
		}
		next_bloc = ft_generate_instruction_bloc(instruction_tab, order);
		(*begin)->next = next_bloc;
		(*begin) = next_bloc;
	}
}

t_instruction_list	*ft_generate_instruction_list(int fd)
{
	t_instruction_list	*instruction_lst;
	t_instruction_list	*begin;
	char				*order;
	char				**instruction_tab;

	instruction_tab = ft_generate_instruction_tab(&order, fd);
	if (!instruction_tab || order == NULL)
		return (ft_free_instruction_tab(instruction_tab), NULL);
	instruction_lst = ft_generate_instruction_bloc(instruction_tab, order);
	if (!instruction_lst)
		return (ft_free_instruction_tab(instruction_tab), NULL);
	if (ft_first_order_is_available(instruction_tab, \
		instruction_lst->instruction) == 0)
		return (ft_free_instruction_tab(instruction_tab), instruction_lst);
	begin = instruction_lst;
	ft_generate_the_list(fd, &begin, instruction_tab);
	ft_free_instruction_tab(instruction_tab);
	return (instruction_lst);
}
