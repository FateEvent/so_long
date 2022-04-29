/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_assign_index.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:15:59 by faventur          #+#    #+#             */
/*   Updated: 2022/04/29 14:26:48 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

static int	*ft_create_arr(t_stack *stack, int size)
{
	t_node	*current;
	int		*arr;
	int		i;

	arr = malloc(sizeof(int) * size);
	if (!stack || !arr)
		return (NULL);
	current = stack->top;
	i = 0;
	while (i < size)
	{
		arr[i] = current->content;
		current = current->next;
		i++;
	}
	return (arr);
}

void	ft_assign_index(t_stack *stack)
{
	t_node	*current;
	int		*arr;
	int		size;
	int		i;
	int		j;

	size = stack->length;
	arr = ft_create_arr(stack, size);
	ft_sort_int_tab(arr, size);
	current = stack->top;
	i = 0;
	j = 0;
	while (current != NULL)
	{
		while (i < size)
		{
			if (current->content == arr[i])
				current->index = i;
			i++;
		}
		i = 0;
		current = current->next;
	}
	free(arr);
}
