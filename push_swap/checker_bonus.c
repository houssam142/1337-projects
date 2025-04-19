/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:47:47 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/15 08:20:28 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	check_result(t_stack *a, t_stack *b)
{
	if (!a)
		return ;
	if (is_sorted(a) && !b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	t_list	*operations;

	stack_b = NULL;
	operations = NULL;
	if (argc < 2)
		return (0);
	stack_a = fill_stack_values(argc, argv);
	read_operations(&operations, &stack_a, &stack_b);
	check_result(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	ft_lstclear(&operations);
	return (0);
}
