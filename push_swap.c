/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:27:49 by jhyokki           #+#    #+#             */
/*   Updated: 2025/03/31 09:56:55 by jhyokki          ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		len;

	if (argc < 2)
	{
		write(2, "Error\n", 6);
		return (1);
	}
	stack_a = create_stack();
	stack_b = create_stack();
	i = 1;
	while (i < argc)
	{
		parse_string(stack_a, argv[i]);
		i++;
	}
	len = count_stack_size(stack_a);
	quicksort(stack_a, stack_b, len);
	free_stack(stack_a);
	free(stack_a);
	free_stack(stack_b);
	free(stack_b);
	return (0);
}
