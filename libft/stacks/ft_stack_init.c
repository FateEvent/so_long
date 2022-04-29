/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stack_init.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 14:11:44 by faventur          #+#    #+#             */
/*   Updated: 2022/04/29 14:26:54 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stacks.h"

void	ft_stack_init(int argc, char *argv[], t_stack *stack)
{
	char	**arg_arr;
	int		i;

	i = 0;
	if (argc == 2)
		arg_arr = ft_split(argv[1], ' ');
	else
	{
		i = 1;
		arg_arr = argv;
	}
	while (arg_arr[i])
	{
		ft_stackadd_bottom(stack, ft_newnode(ft_atoi(arg_arr[i])));
		i++;
	}
	if (argc == 2)
		free(arg_arr);
}
