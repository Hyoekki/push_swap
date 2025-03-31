/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:28:33 by jhyokki           #+#    #+#             */
/*   Updated: 2025/03/31 08:57:46 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_duplicate(int n, t_stack *stack_a)
{
	t_node	*temp;

	temp = stack_a->head;
	while (temp)
	{
		if (n == temp->data)
			return (1);
		temp = temp->next;
	}
	return (0);
}

int	parse_string(t_stack *stack, char *str)
{
	char	**numbers;
	int		i;
	int		len;

	numbers = ft_split(str, ' ');
	len = 0;
	while (numbers[len])
	{
		if (is_duplicate(ft_atoi(numbers[len]), stack))
		{
			write(2, "Error\n", 6);
			while (len--)
				free(numbers[len]);
			free(numbers);
			exit(EXIT_FAILURE);
		}
		append_node(stack, create_node(ft_atoi(numbers[len])));
		len++;
	}
	i = len;
	while (i > 0)
		free(numbers[--i]);
	free(numbers);
	return (len);
}
