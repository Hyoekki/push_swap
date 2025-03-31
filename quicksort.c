/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:18:34 by jhyokki           #+#    #+#             */
/*   Updated: 2025/03/31 11:05:16 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <limits.h>
#include "push_swap.h"

int	count_stack_size(t_stack *stack)
{
	t_node	*temp;
	int		i;

	temp = stack->head;
	i = 0;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	return (i);
}

int	is_sorted(t_stack *stack, char a_or_b)
{
	t_node	*temp;

	temp = stack->head;
	if (a_or_b == 'a')
	{
		while (temp && temp->next)
		{
			if (temp->data > temp->next->data)
				return (0);
			temp = temp->next;
		}
		return (1);
	}
	else if (a_or_b == 'b')
	{
		while (temp && temp->next)
		{
			if (temp->data < temp->next->data)
				return (0);
			temp = temp->next;
		}
		return (1);
	}
	return (0);
}

void	quicksort_b(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	pivot;
	int	pushed;
	int	rotations;
	int	i;

	if (len <= 1 || is_sorted(stack_b, 'b'))
		return ;
	if (len == 2 && stack_b->head->data < stack_b->head->next->data)
		return (sb(stack_b));
	pivot = get_pivot(stack_b, len);
	pushed = 0;
	rotations = 0;
	i = 0;
	while (i < len)
	{
		if (stack_b->head && stack_b->head->data >= pivot)
		{
			pa(stack_b, stack_a);
			if (stack_a->head->next && stack_a->head->data > stack_a->head->next->data)
				sa(stack_a);
			pushed++;
		}
		else if (!is_sorted(stack_b, 'b'))
		{
			rb(stack_b);
			rotations++;
		}
		i++;
	}
	while (rotations-- && !is_sorted(stack_b, 'b'))
		rrb(stack_b);
	if (!is_sorted(stack_b, 'b'))
		quicksort_b(stack_a, stack_b, len - pushed);
	if (!is_sorted(stack_a, 'a'))
		quicksort_a(stack_a, stack_b, pushed);
	while (pushed--)
		pb(stack_a, stack_b);
}

void	quicksort_a(t_stack *stack_a, t_stack *stack_b, int len)
{
	int	pivot;
	int	pushed;
	int	rotations;
	int	i;

	if (len <= 1 || is_sorted(stack_a, 'a'))
		return ;
	if (len == 2 && stack_a->head->data > stack_a->head->next->data)
		return (sa(stack_a));
	pivot = get_pivot(stack_a, len);
	pushed = 0;
	rotations = 0;
	i = 0;
	while (i < len)
	{
		if (stack_a->head && stack_a->head->data <= pivot)
		{
			pb(stack_a, stack_b);
			if (stack_b->head->next && stack_b->head->data < stack_b->head->next->data)
				sb(stack_b);
			pushed++;
		}
		else if (!is_sorted(stack_a, 'a'))
		{
			ra(stack_a);
			rotations++;
		}
		i++;
	}
	while (rotations-- && !is_sorted(stack_a, 'a'))
		rra(stack_a);
	if (!is_sorted(stack_a, 'a'))
		quicksort_a(stack_a, stack_b, len - pushed);
	if (!is_sorted(stack_b, 'b'))
		quicksort_b(stack_a, stack_b, pushed);
	while (pushed--)
		pa(stack_b, stack_a);
}

void	quicksort(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len == 3)
		sort_three(stack_a, 'a');
	else
		quicksort_a(stack_a, stack_b, len);
}
