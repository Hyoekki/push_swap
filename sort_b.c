/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:37:15 by jhyokki           #+#    #+#             */
/*   Updated: 2025/03/31 19:37:30 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_back_b(t_stack *stack, int rotations, int len)
{
	int	forward_rotations;

	if (rotations > 0 && rotations <= len / 2)
	{
		while (rotations--)
			rrb(stack);
	}
	else if (rotations > len / 2)
	{
		forward_rotations = len - rotations;
		while (forward_rotations--)
			rb(stack);
	}
}

int	partition_b(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	pivot;
	int	pushed;
	int	rotations;
	int	i;

	pivot = get_pivot(stack_b, len);
	pushed = 0;
	rotations = 0;
	i = 0;
	while (i < len && rotations < len - pushed && pushed < len - rotations)
	{
		if (stack_b->head && stack_b->head->data >= pivot)
		{
			pa(stack_b, stack_a);
			pushed++;
		}
		else
		{
			rb(stack_b);
			rotations++;
		}
		i++;
	}
	rotate_back_b(stack_b, rotations, len);
	return (pushed);
}

void	quicksort_b(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	pushed;
	int	current_len;

	if (len <= 1 || is_sorted(stack_b, 'b'))
		return ;
	if (len == 2 && stack_b->head->data < stack_b->head->next->data)
		return (sb(stack_b));
	current_len = count_stack_size(stack_b);
	if (current_len == 3)
	{
		sort_three(stack_b, 'b');
		return ;
	}
	pushed = partition_b(stack_a, stack_b, len);
	quicksort_b(stack_a, stack_b, len - pushed);
	quicksort_a(stack_a, stack_b, pushed);
	while (pushed--)
		pb(stack_a, stack_b);
}
