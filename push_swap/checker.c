/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 20:47:47 by hounejja          #+#    #+#             */
/*   Updated: 2025/01/25 08:28:26 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header/push_swap.h"

void check_result(t_stack *a, t_stack *b)
{
	if (is_sorted(a) && !b)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
}

int main(int argc, char **argv)
{
	t_stack *stack_a;
	t_stack *stack_b = NULL;
	t_list  *operations = NULL;

	if (argc < 2)
		return (0);
	stack_a = fill_stack_values(argc, argv);
	read_operations(&operations);
	while (operations)
	{
		execute_operation(&stack_a, &stack_b, (char *)operations->content);
		operations = operations->next;
	}
	check_result(stack_a, stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	ft_lstclear(&operations, free);
	return (0);
}

