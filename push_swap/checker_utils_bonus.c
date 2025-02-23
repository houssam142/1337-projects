/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 10:19:31 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/15 08:11:39 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	execute_operation(t_stack **a, t_stack **b, char *op)
{
	if (!ft_strcmp(op, "sa\n"))
		swap(*a);
	else if (!ft_strcmp(op, "sb\n"))
		swap(*b);
	else if (!ft_strcmp(op, "ss\n"))
		do_ss(a, b);
	else if (!ft_strcmp(op, "pa\n"))
		push(b, a);
	else if (!ft_strcmp(op, "pb\n"))
		push(a, b);
	else if (!ft_strcmp(op, "ra\n"))
		rotate(a);
	else if (!ft_strcmp(op, "rb\n"))
		rotate(b);
	else if (!ft_strcmp(op, "rr\n"))
		do_rr_bonus(a, b);
	else if (!ft_strcmp(op, "rra\n"))
		rev_rotate(a);
	else if (!ft_strcmp(op, "rrb\n"))
		rev_rotate(b);
	else if (!ft_strcmp(op, "rrr\n"))
		do_rrr_bonus(a, b);
	else
		return (0);
	return (1);
}

void	read_operations(t_list **operations, t_stack **a, t_stack **b)
{	
	char	*line;

	line = get_next_line(0);
	while (line)
	{
		if (!execute_operation(a, b, line))
		{
			free(line);
			handle_error_and_exit(NULL, a, b, operations);
		}
		free(line);
		line = get_next_line(0);
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
