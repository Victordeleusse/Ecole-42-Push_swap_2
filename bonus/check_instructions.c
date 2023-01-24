/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instructions.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 20:10:32 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/24 20:10:36 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

char	*ft_give_instruction(char a, char b, char c)
{
	char	*instruction;

	instruction = ft_calloc(sizeof(char), 4);
	instruction[0] = a;
	instruction[1] = b;
	instruction[2] = c;
	return (instruction);
}

char	**ft_generate_instruction_tab(char **order, int fd)
{
	char	**instruction_tab;

	instruction_tab = ft_calloc(sizeof(char *), 12);
	if (!instruction_tab)
		return (NULL);
	*order = get_next_line(fd);
	if (*order == NULL)
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

int	ft_first_order_is_available(char **instruction_tab, char *order)
{
	int		count;
	size_t	order_len;

	order_len = ft_strlen(order);
	count = 0;
	while (instruction_tab[count])
	{
		if ((ft_strncmp(instruction_tab[count], order, order_len) == 0) && \
			ft_strlen(instruction_tab[count]) == order_len)
			return (1);
		count++;
	}
	return (0);
}

int	ft_order_is_available(char **instruction_tab, char *order)
{
	int		count;
	size_t	order_len;

	order_len = ft_strlen(order);
	count = 0;
	while (instruction_tab[count])
	{
		if ((ft_strncmp(instruction_tab[count], order, order_len - 1) == 0) && \
			ft_strlen(instruction_tab[count]) == order_len - 1)
			return (1);
		count++;
	}
	return (0);
}
