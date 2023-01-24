/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/13 11:12:15 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/24 19:21:16 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_init_distance_and_signe(const char *str, int *isneg)
{
	long	i;

	i = 0;
	while (str[i] != '\0' && (str[i] == 32 || str[i] == '\t' || str[i] == '\n'
			|| str[i] == '\r' || str[i] == '\v' || str[i] == '\f'))
		i++;
	if (str[i] != '\0' && str[i] == '-')
	{
		*isneg = 1;
		i++;
	}
	else if (str[i] == '+')
		i++;
	return (i);
}

long	ft_atoi(const char *str, int *count)
{
	long	i;
	long	nbr;
	int		isneg;

	nbr = 0;
	isneg = 0;
	i = ft_init_distance_and_signe(str, &isneg);
	while (str[i] != '\0' && ft_isdigit(str[i]))
	{
		nbr = (nbr * 10) + (str[i++] - '0');
		if ((nbr > 2147483647 && isneg == 0) || \
			(nbr > 2147483648 && isneg == 1))
			return (3147483647);
		*count = *count + 1;
	}
	if (str[i])
		return (3147483647);
	if (isneg == 1)
		return (-nbr);
	return (nbr);
}

/*
int	main(void)
{
	const char	test[] = "    ++5463afG";

	printf("ft_atoi : %d\n\n", ft_atoi(test));
	printf("atoi    : %d", atoi(test));
	return (0);
}
*/