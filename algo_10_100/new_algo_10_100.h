/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo_10_100.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:32:18 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/17 20:01:36 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_ALGO_10_100_H
# define NEW_ALGO_10_100_H

t_stack_list	*ft_get_last_stack(t_stack_list **stack_a);
void			ft_exit_weight_per_elem(t_stack_list *element);
void			ft_init_exit_weight(t_stack_list **stack_a);
t_stack_list	*ft_get_heaviest_elem(t_stack_list **stack_a);

#endif