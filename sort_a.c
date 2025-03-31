/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/31 19:35:31 by jhyokki           #+#    #+#             */
/*   Updated: 2025/03/31 19:36:54 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_back_a(t_stack *stack, int rotations, int len)
{
	int	forward_rotations;

	if (rotations > 0 && rotations <= len / 2)
	{
		while (rotations--)
			rra(stack);
	}
	else if (rotations > len / 2)
	{
		forward_rotations = len - rotations;
		while (forward_rotations--)
			ra(stack);
	}
}

int	partition_a(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	pivot;
	int	pushed;
	int	rotations;
	int	i;

	pivot = get_pivot(stack_a, len);
	pushed = 0;
	rotations = 0;
	i = 0;
	while (i < len && rotations < len - pushed && pushed < len - rotations)
	{
		if (stack_a->head && stack_a->head->data <= pivot)
		{
			pb(stack_a, stack_b);
			pushed++;
		}
		else
		{
			ra(stack_a);
			rotations++;
		}
		i++;
	}
	rotate_back_a(stack_a, rotations, len);
	return (pushed);
}

void	quicksort_a(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	pushed;
	int	curr_size;

	if (len <= 1 || is_sorted(stack_a, 'a'))
		return ;
	if (len == 2 && stack_a->head->data > stack_a->head->next->data)
		return (sa(stack_a));
	curr_size = count_stack_size(stack_a);
	if (curr_size == 3)
	{
		sort_three(stack_a, 'a');
		return ;
	}
	pushed = partition_a(stack_a, stack_b, len);
	quicksort_a(stack_a, stack_b, len - pushed);
	quicksort_b(stack_a, stack_b, pushed);
	while (pushed--)
		pa(stack_b, stack_a);
}
