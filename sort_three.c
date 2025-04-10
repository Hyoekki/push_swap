/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/29 20:20:17 by jhyokki           #+#    #+#             */
/*   Updated: 2025/04/10 18:25:28 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three_a(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->data;
	b = stack->head->next->data;
	c = stack->head->next->next->data;
	if (a > b && b < c && a < c)
		sa(stack);
	else if (a < b && b > c && a < c)
	{
		sa(stack);
		ra(stack);
	}
	else if (a < b && b > c && a > c)
		rra(stack);
	else if (a > b && b < c && a > c)
		ra(stack);
	else if (a > b && b > c)
	{
		sa(stack);
		rra(stack);
	}
}

void	sort_three_b(t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = stack->head->data;
	b = stack->head->next->data;
	c = stack->head->next->next->data;
	if (a < b && b > c && a > c)
		sb(stack);
	else if (a > b && b < c && a > c)
	{
		sb(stack);
		rb(stack);
	}
	else if (a > b && b < c && a < c)
		rrb(stack);
	else if (a < b && b > c && a < c)
		rb(stack);
	else if (a < b && b < c)
	{
		sb(stack);
		rrb(stack);
	}
}

void	sort_three(t_stack *stack, char c, int len)
{
	if (c == 'a')
	{
		if (len == 2 && stack->head->data > stack->head->next->data)
			sa(stack);
		else
			sort_three_a(stack);
	}
	else if (c == 'b')
	{
		if (len == 2 && stack->head->data < stack->head->next->data)
			sb(stack);
		else
			sort_three_b(stack);
	}
}
