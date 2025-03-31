/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:13:09 by jhyokki           #+#    #+#             */
/*   Updated: 2025/03/31 19:32:34 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_min_position(t_stack *stack)
{
	t_node	*current;
	int		min_value;
	int		min_pos;
	int		current_pos;

	if (!stack || !stack->head)
		return (-1);
	current = stack->head;
	min_value = current->data;
	min_pos = 0;
	current_pos = 0;
	while (current)
	{
		if (current->data < min_value)
		{
			min_value = current->data;
			min_pos = current_pos;
		}
		current = current->next;
		current_pos++;
	}
	return (min_pos);
}

void	sort_five(t_stack *stack_a, t_stack *stack_b)
{
	int	min_pos;
	int	stack_size;
	int	i;

	i = 0;
	while (i < 2)
	{
		stack_size = count_stack_size(stack_a);
		min_pos = find_min_position(stack_a);
		if (min_pos <= stack_size / 2)
			while (min_pos-- > 0)
				ra(stack_a);
		else
			while (min_pos++ < stack_size)
				rra(stack_a);
		pb(stack_a, stack_b);
		i++;
	}
	sort_three(stack_a, 'a');
	pa(stack_b, stack_a);
	pa(stack_b, stack_a);
}
