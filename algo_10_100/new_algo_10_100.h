/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_algo_10_100.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:32:18 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/18 14:26:17 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NEW_ALGO_10_100_H
# define NEW_ALGO_10_100_H

///////////////////// INIT_WEIGHT ////////////////////////////

t_stack_list	*ft_get_last_stack(t_stack_list **stack_a);
void			ft_exit_weight_per_elem(t_stack_list *element);
void			ft_init_exit_weight(t_stack_list **stack_a);
t_stack_list	*ft_get_heaviest_elem(t_stack_list **stack_a);

///////////////////// GET_ALREADY_SORT_LIST ///////////////////

void			ft_init_already_sort_below(t_stack_list **stack_a);
int				ft_get_biggest_index_below_heaviest(t_stack_list **stack_a);
void			ft_init_already_sort_above(t_stack_list **stack_a);
int				ft_calculate_mediane(t_stack_list **stack_a);
void			ft_send_from_a_to_b(t_stack_list **stack_a, \
		t_stack_list **stack_b, t_instruction_list **instruction_list);

///////////////////// GET_NB_OPERATIONS //////////////////////

int				ft_get_on_top_of_b(t_stack_list **stack_b, t_stack_list *target);

#endif