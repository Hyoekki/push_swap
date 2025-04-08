/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/27 10:28:33 by jhyokki           #+#    #+#             */
/*   Updated: 2025/04/08 13:07:10 by jhyokki          ###   ########.fr       */
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

int	is_valid_number(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (!str[i])
		return (0);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	check_duplicates_in_input(char **numbers, int i)
{
	int	j;

	j = 0;
	while (j < i)
	{
		if (ft_atol(numbers[j]) == ft_atol(numbers[i]))
			return (1);
		j++;
	}
	return (0);
}

int	validate_and_add_number(t_stack *stack, char *number)
{
	long	value;

	if (!is_valid_number(number))
		return (-1);
	value = ft_atol(number);
	if (value > 2147483647 || value < -2147483648
		|| is_duplicate((int)value, stack))
		return (-1);
	if (!append_node(stack, create_node((int)value)))
		return (-1);
	return (0);
}

int	parse_string(t_stack *stack, char *str)
{
	char	**numbers;
	int		i;

	if (!str || !*str)
		return (-1);
	if (*str == ' ')
		return (-1);
	numbers = ft_split(str, ' ');
	if (!numbers)
		return (-1);
	i = 0;
	while (numbers[i])
	{
		if (check_duplicates_in_input(numbers, i)
			|| validate_and_add_number(stack, numbers[i]) == -1)
		{
			free_array_of_strings(numbers);
			return (-1);
		}
		i++;
	}
	free_array_of_strings(numbers);
	return (i);
}
