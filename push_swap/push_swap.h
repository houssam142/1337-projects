/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hounejja <hounejja@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/27 08:27:28 by hounejja          #+#    #+#             */
/*   Updated: 2025/02/15 08:09:34 by hounejja         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include "get_next_line.h"

typedef struct s_stack
{
	int				value;
	int				index;
	int				pos;
	int				target_pos;
	int				cost_a;
	int				cost_b;
	struct s_stack	*next;
}					t_stack;

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

t_stack			*fill_stack_values(int ac, char **av);
int				arg_is_number(char *av);
void			assign_index(t_stack *stack_a, int ac);
int				is_sorted(t_stack *stack);
void			push_swap(t_stack **stack_a, t_stack **stack_b, int stack_size);
void			tiny_sort(t_stack **stack);
void			sort(t_stack **stack_a, t_stack **stack_b);
int				get_lowest_index_position(t_stack **stack);
void			get_target_position(t_stack **stack_a, t_stack **stack_b);
void			get_cost(t_stack **stack_a, t_stack **stack_b);
void			do_cheapest_move(t_stack **stack_a, t_stack **stack_b);
void			do_move(t_stack **a, t_stack **b, int cost_a, int cost_b);
void			do_pa(t_stack **stack_a, t_stack **stack_b);
void			do_pb(t_stack **stack_a, t_stack **stack_b);
void			do_sa(t_stack **stack_a);
void			do_sb(t_stack **stack_b);
void			do_ss(t_stack **stack_a, t_stack **stack_b);
void			do_ra(t_stack **stack_a);
void			do_rb(t_stack **stack_b);
void			do_rr(t_stack **stack_a, t_stack **stack_b);
void			do_rrr(t_stack **stack_a, t_stack **stack_b);
void			do_rra(t_stack **stack_a);
void			do_rrb(t_stack **stack_b);
void			swap(t_stack *stack);
void			rev_rotate(t_stack **stack);
void			rotate(t_stack **stack);
void			push(t_stack **src, t_stack **dest);
t_stack			*get_stack_bottom(t_stack *stack);
t_stack			*get_stack_before_bottom(t_stack *stack);
t_stack			*stack_new(int value);
void			stack_add_bottom(t_stack **stack, t_stack *new);
int				get_stack_size(t_stack *stack);
void			free_stack(t_stack **stack);
long int		ft_atoi(const char *str);
void			ft_putstr(char *str);
int				nb_abs(int nb);
int				is_digit(char c);
int				is_sign(char c);
int				nbstr_cmp(const char *s1, const char *s2);
char			**ft_split(char const *s);
char			*ft_strdup(const char *str);
int				stack_contains(t_stack *stack, long int nb);
void			ft_lstclear(t_list **lst);
t_list			*ft_lstnew(void *content);
int				execute_operation(t_stack **a, t_stack **b, char *op);
int				ft_isspace(char c);
void			handle_error_and_exit(char **num, t_stack **stack_a,
					t_stack **stack_b, t_list **operations);

#endif
