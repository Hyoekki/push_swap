/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:27:49 by jhyokki           #+#    #+#             */
/*   Updated: 2025/04/08 13:07:18 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_error(t_stack *stack_a, t_stack *stack_b)
{
	free_stack(stack_a);
	free(stack_a);
	free_stack(stack_b);
	free(stack_b);
	write(2, "Error\n", 6);
}

int	parse_arguments(t_stack *stack_a, int argc, char **argv)
{
	int	i;
	int	parse_result;

	i = 1;
	while (i < argc)
	{
		parse_result = parse_string(stack_a, argv[i]);
		if (parse_result == -1)
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		len;

	if (argc < 2)
		return (1);
	if (!initialize_stacks(&stack_a, &stack_b))
		return (1);
	if (!parse_arguments(stack_a, argc, argv))
	{
		handle_error(stack_a, stack_b);
		return (1);
	}
	len = count_stack_size(stack_a);
	if (len > 0)
		quicksort(stack_a, stack_b, len);
	free_stack(stack_a);
	free(stack_a);
	free_stack(stack_b);
	free(stack_b);
	return (0);
}
