/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/01 18:28:03 by jhyokki           #+#    #+#             */
/*   Updated: 2025/04/01 18:32:24 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*create_node(int data)
{
	t_node	*new_node;

	new_node = malloc(sizeof * new_node);
	if (!new_node)
		return (NULL);
	new_node->data = data;
	new_node->next = NULL;
	new_node->prev = NULL;
	return (new_node);
}

t_stack	*append_node(t_stack *stack, t_node *node)
{
	if (!stack || !node)
		return (NULL);
	if (!stack->head)
	{
		stack->head = node;
		stack->tail = node;
	}
	else
	{
		stack->tail->next = node;
		node->prev = stack->tail;
		stack->tail = node;
	}
	return (stack);
}

void	free_stack(t_stack *stack)
{
	t_node	*current;
	t_node	*temp;

	current = stack->head;
	while (current)
	{
		temp = current->next;
		free(current);
		current = temp;
	}
}

t_stack	*create_stack(void)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	if (!stack)
		return (NULL);
	stack->head = NULL;
	stack->tail = NULL;
	return (stack);
}

int	initialize_stacks(t_stack **stack_a, t_stack **stack_b)
{
	*stack_a = create_stack();
	*stack_b = create_stack();
	if (!*stack_a || !*stack_b)
	{
		free(*stack_a);
		free(*stack_b);
		write(2, "Error\n", 6);
		return (0);
	}
	return (1);
}
