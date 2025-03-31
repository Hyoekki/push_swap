/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_pivot.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jhyokki <jhyokki@student.hive.fi>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/30 14:06:59 by jhyokki           #+#    #+#             */
/*   Updated: 2025/03/31 19:19:21 by jhyokki          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*push_to_arr(t_stack *stack, int len)
{
	t_node	*temp;
	int		i;
	int		*arr;

	arr = malloc(sizeof * arr * len);
	if (!arr)
		exit(EXIT_FAILURE);
	temp = stack->head;
	if (!temp)
		exit(EXIT_FAILURE);
	i = 0;
	while (i < len && temp)
	{
		arr[i++] = temp->data;
		temp = temp->next;
	}
	return (arr);
}

void	insertion_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	key;

	i = 1;
	while (i < len)
	{
		key = arr[i];
		j = i - 1;
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
		i++;
	}
}

int	get_pivot(t_stack *stack, int len)
{
	int		*arr;
	int		pivot;

	arr = push_to_arr(stack, len);
	if (!arr)
		exit(EXIT_FAILURE);
	insertion_sort(arr, len);
	if (len % 2 == 0)
		pivot = arr[(len / 2) - 1];
	else
		pivot = arr[len / 2];
	free(arr);
	return (pivot);
}
