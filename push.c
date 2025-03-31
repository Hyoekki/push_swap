/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:28:18 by jhyokki           #+#    #+#             */
/*   Updated: 2025/03/31 08:56:46 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack *src_stack, t_stack *dest_stack)
{
	t_node	*node_to_push;

	if (!src_stack || !dest_stack || !src_stack->head)
		return ;
	node_to_push = src_stack->head;
	src_stack->head = node_to_push->next;
	if (!src_stack->head)
		src_stack->tail = NULL;
	else
		src_stack->head->prev = NULL;
	node_to_push->next = dest_stack->head;
	node_to_push->prev = NULL;
	if (dest_stack->head)
		dest_stack->head->prev = node_to_push;
	else
		dest_stack->tail = node_to_push;
	dest_stack->head = node_to_push;
}

void	pa(t_stack *stack_b, t_stack *stack_a)
{
	push(stack_b, stack_a);
	write(1, "pa\n", 3);
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a, stack_b);
	write(1, "pb\n", 3);
}
