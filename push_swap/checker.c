/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:47:47 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/01 14:12:29 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void	check_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && !b)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
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
