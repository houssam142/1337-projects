/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 17:42:51 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/15 08:13:49 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	do_rra_bonus(t_stack **stack_a)
{
	rev_rotate(stack_a);
}

void	do_rrb_bonus(t_stack **stack_b)
{
	rev_rotate(stack_b);
}

void	do_rrr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
}

void	do_rr_bonus(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
