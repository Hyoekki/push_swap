/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/28 09:18:34 by jhyokki           #+#    #+#             */
/*   Updated: 2025/04/08 14:01:04 by jhyokki          ###   ########.fr       */
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

void	quicksort(t_stack *stack_a, t_stack *stack_b, int len)
{
	if (len == 1)
		exit(EXIT_SUCCESS);
	if (len == 2 && is_sorted(stack_a, 'a'))
		exit(EXIT_SUCCESS);
	if (len == 2 && !is_sorted(stack_a, 'a'))
	{
		sa(stack_a);
		exit(EXIT_SUCCESS);
	}
	if (len <= 5 && !is_sorted(stack_a, 'a'))
	{
		if (len == 3)
			sort_three(stack_a, 'a');
		else
			sort_five(stack_a, stack_b);
	}
	else
		quicksort_a(stack_a, stack_b, len);
}
