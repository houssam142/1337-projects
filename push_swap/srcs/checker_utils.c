/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:19:31 by hounejja          #+#    #+#             */
/*   Updated: 2025/01/28 12:13:51 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	execute_operation(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp(op, "sa"))
		swap(*a);
	else if (!ft_strcmp(op, "sb"))
		swap(*b);
	else if (!ft_strcmp(op, "ss"))
		do_ss(a, b);
	else if (!ft_strcmp(op, "pa"))
		push(b, a);
	else if (!ft_strcmp(op, "pb"))
		push(a, b);
	else if (!ft_strcmp(op, "ra"))
		rotate(a);
	else if (!ft_strcmp(op, "rb"))
		rotate(b);
	else if (!ft_strcmp(op, "rr"))
		do_rr(a, b);
	else if (!ft_strcmp(op, "rra"))
		rev_rotate(a);
	else if (!ft_strcmp(op, "rrb"))
		rev_rotate(b);
	else if (!ft_strcmp(op, "rrr"))
		do_rrr(a, b);
	else
		handle_error_and_exit(&op);
}

void	read_operations(t_list **operations)
{	
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		ft_lstadd_back(operations, ft_lstnew(line));
	}
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	if (s1[i] != s2[i])
		return (s1[i] - s2[i]);
	return (0);
}
