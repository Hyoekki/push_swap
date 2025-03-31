/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:38:42 by jhyokki           #+#    #+#             */
/*   Updated: 2025/03/27 18:39:35 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_rotate(t_stack *stack)
{
	t_node	*last_node;

	if (!stack || !stack->head || stack->head == stack->tail)
		return ;
	last_node = stack->tail;
	stack->tail = last_node->prev;
	stack->tail->next = NULL;
	stack->head->prev = last_node;
	last_node->next = stack->head;
	last_node->prev = NULL;
	stack->head = last_node;
}

void	rra(t_stack *stack_a)
{
	reverse_rotate(stack_a);
	write(1, "rra\n", 4);
}

void	rrb(t_stack *stack_b)
{
	reverse_rotate(stack_b);
	write(1, "rrb\n", 4);
}
