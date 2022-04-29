/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stackdelone.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 20:16:24 by faventur          #+#    #+#             */
/*   Updated: 2022/04/29 20:18:59 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_stackdelone() function frees the memory of the element passed
** as a parameter with the del function and free(3). The memory of
** next must be freed.
*/

#include "stacks.h"

void	ft_stackdelone(t_stack *stack, void (*del)(void *))
{
	if (!stack || !del)
		return ;
	del(stack->content);
	free(stack);
}
