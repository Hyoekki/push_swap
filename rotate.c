/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 18:38:08 by jhyokki           #+#    #+#             */
/*   Updated: 2025/03/27 18:38:56 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate(t_stack *stack)
{
	t_node	*first_node;

	if (!stack || !stack->head || stack->head == stack->tail)
		return ;
	first_node = stack->head;
	stack->head = first_node->next;
	stack->head->prev = NULL;
	stack->tail->next = first_node;
	first_node->prev = stack->tail;
	first_node->next = NULL;
	stack->tail = first_node;
}

void	ra(t_stack *stack_a)
{
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_stack *stack_b)
{
	rotate(stack_b);
	write(1, "rb\n", 3);
}
