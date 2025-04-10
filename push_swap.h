/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:27:38 by jhyokki           #+#    #+#             */
/*   Updated: 2025/04/10 18:22:45 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "libft/include/libft.h"

typedef struct s_node
{
	int				data;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_stack
{
	t_node	*head;
	t_node	*tail;
}	t_stack;

int		parse_string(t_stack *stack, char *str);
t_stack	*append_node(t_stack *stack, t_node *node);
int		initialize_stacks(t_stack **stack_a, t_stack **stack_b);
void	sort_five(t_stack *stack_a, t_stack *stack_b);
int		is_sorted(t_stack *stack, char a_or_b);
void	quicksort(t_stack *stack_b, t_stack *stack_a, int len);
void	quicksort_a(t_stack *stack_b, t_stack *stack_a, int len);
void	quicksort_b(t_stack *stack_b, t_stack *stack_a, int len);
int		count_stack_size(t_stack *stack);
int		get_pivot(t_stack *stack, int len);
void	sort_three(t_stack *stack, char c, int len);
int		get_pivot(t_stack *stack, int len);
int		is_duplicate(int n, t_stack *stack_a);
int		parse_string(t_stack *stack, char *str);
t_node	*create_node(int data);
t_stack	*append_node(t_stack *stack, t_node *node);
void	free_stack(t_stack *stack);
void	pa(t_stack *stack_a, t_stack *stack_b);
void	pb(t_stack *stack_b, t_stack *stack_a);
void	sa(t_stack *stack_a);
void	sb(t_stack *stack_b);
void	ra(t_stack *stack_a);
void	rb(t_stack *stack_b);
void	rra(t_stack *stack_a);
void	rrb(t_stack *stack_a);
void	push(t_stack *src_stack, t_stack *dest_stack);
void	swap(t_stack *stack);
void	rotate(t_stack *stack);
void	reverse_rotate(t_stack *stack);

#endif
