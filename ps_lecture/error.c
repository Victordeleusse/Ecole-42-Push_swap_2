/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 14:39:47 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/23 10:57:04 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_is_int(int number, char *str, int count)
{
	if ((str[0] == '-' && number > 0) || (str[0] != '-' && number < 0))
		return (ft_putstr_fd(ERR_NOTANINT, 2), 0);
	else if (count == 0)
		return (ft_putstr_fd(ERR_WRONGTYPEARGS, 2), 0);
	return (1);
}

int	ft_is_already_present(int number, int *tab, int taille)
{
	int	j;

	j = 0;
	while (j < taille)
	{
		if (tab[j] == number)
			return (ft_putstr_fd(ERR_DUPLICATEARGS, 2), 0);
		j++;
	}
	return (1);
}
