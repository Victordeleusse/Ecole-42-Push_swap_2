/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo_3_5.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 14:48:50 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/24 11:03:42 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ALGO_3_5_H
# define ALGO_3_5_H

int				ft_already_sort_5(t_stack_list **stack);
int				ft_get_distance(t_stack_list **stack, int mediane_index);
void			ft_prepare_stack_4(t_stack_list **stack1, \
					t_stack_list **stack2, int mediane_index, \
					t_instruction_list **instruction_list);
void			ft_prepare_stack_3(t_stack_list **stack1, \
					t_stack_list **stack2, int mediane_index, \
					t_instruction_list **instruction_list);
void			ft_prepare_stack_3_bis(t_stack_list **stack1, \
					t_stack_list **stack2, int mediane_index, \
					t_instruction_list **instruction_list);
void			ft_prepare_stack_2(t_stack_list **stack2, \
					t_instruction_list **instruction_list);
void			ft_size_mini(t_stack_list **stack_a, \
					t_instruction_list **instruction_list, \
					int size_stack1);
void			ft_sort_5(t_stack_list **stack1, t_stack_list **stack2, \
					t_instruction_list **instruction_list);

#endif