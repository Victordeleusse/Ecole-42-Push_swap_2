/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lecture.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vde-leus <vde-leus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 09:54:17 by vde-leus          #+#    #+#             */
/*   Updated: 2023/01/20 17:50:27 by vde-leus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LECTURE_H
# define LECTURE_H

# define ERR_NOTANINT "Error\n"
# define ERR_WRONGTYPEARGS "Error\n"
# define ERR_DUPLICATEARGS "Error\n"

typedef struct s_stack_list
{
	int					data;
	int					index_sorted;
	int					bloc;
	int					exit_weight;
	int					is_already_sort;
	int					distance_to_sort;
	struct s_stack_list	*previous;
	struct s_stack_list	*next;
}t_stack_list;

int				*ft_generate_tab_int(int argc, char **argv);
t_stack_list	*ft_generate_stack_element(int number);
t_stack_list	**ft_generate_full_stack(int *tab, int argc);
t_stack_list	**ft_generate_empty_stack(int argc);

/////////////////////////////// ERROR.C////////////////////////////////

int				ft_is_int(int number, char *str, int count);
int				ft_is_already_present(int number, int *tab, int taille);

#endif