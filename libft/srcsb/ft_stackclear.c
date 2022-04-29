/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackclear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 09:53:37 by faventur          #+#    #+#             */
/*   Updated: 2022/04/18 17:08:51 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_stackclear() function suppresses and frees the memory of the
** the element passed as a parameter and of all the following elements
** by using free(3). Finally, the initial pointer is set to NULL.
*/

#include "stacks.h"

void	ft_stackclear(t_stack **stack)
{
	t_node	*current;
	t_node	*delenda;

	if (*stack != NULL)
	{
		current = (*stack)->top;
		while (current != NULL)
		{
			delenda = current;
			current = current->next;
			free(delenda);
		}
		free(*stack);
		*stack = NULL;
	}
}
