/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/15 07:55:11 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/16 10:26:35 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "get_next_line.h"
# include "push_swap.h"
# include <unistd.h>

void			read_operations(t_list **operations, t_stack **a, t_stack **b);
void			do_rra_bonus(t_stack **stack_a);
void			do_rrb_bonus(t_stack **stack_b);
void			do_rrr_bonus(t_stack **stack_a, t_stack **stack_b);
void			do_rr_bonus(t_stack **stack_a, t_stack **stack_b);
int				ft_strcmp(char *s1, char *s2);

#endif