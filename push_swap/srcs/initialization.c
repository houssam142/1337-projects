/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 14:44:42 by mcombeau          #+#    #+#             */
/*   Updated: 2025/01/29 14:52:15 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header/push_swap.h"

void	ft_free_split(char **split)
{
	int	i;

	i = 0;
	if (!split)
		return ;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

void	handle_error_and_exit(char **num)
{
	ft_free_split(num);
	write(1, "Error\n", 6);
	exit(1);
}

static void	process_num(t_stack **stack, char *str, char **num)
{
	long int	nb;

	nb = ft_atoi(str);
	if (nb > INT_MAX || nb < INT_MIN || stack_contains(*stack, nb))
		handle_error_and_exit(num);
	if (!*stack)
		*stack = stack_new(nb);
	else
		stack_add_bottom(stack, stack_new(nb));
}

t_stack	*fill_stack_values(int ac, char **av)
{
	t_stack	*stack_a;
	char	**num;
	int		i;
	int		j;

	stack_a = NULL;
	i = 1;
	while (i < ac)
	{
		num = ft_split(av[i], ' ');
		if (!num || !*num)
			handle_error_and_exit(NULL);
		j = 0;
		while (num[j])
		{
			if (!arg_is_number(num[j]))
				handle_error_and_exit(num);
			process_num(&stack_a, num[j++], num);
		}
		ft_free_split(num);
		i++;
	}
	return (stack_a);
}

void	assign_index(t_stack *stack_a, int stack_size)
{
	t_stack	*ptr;
	t_stack	*highest;
	int		value;

	while (--stack_size > 0)
	{
		ptr = stack_a;
		value = INT_MIN;
		highest = NULL;
		while (ptr)
		{
			if (ptr->value == INT_MIN && ptr->index == 0)
				ptr->index = 1;
			if (ptr->value > value && ptr->index == 0)
			{
				value = ptr->value;
				highest = ptr;
				ptr = stack_a;
			}
			else
				ptr = ptr->next;
		}
		if (highest != NULL)
			highest->index = stack_size;
	}
}
