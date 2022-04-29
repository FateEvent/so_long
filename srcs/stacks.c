/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:12:14 by faventur          #+#    #+#             */
/*   Updated: 2022/04/29 20:38:15 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_star.h"

void	ft_stack_init(t_stack *stack)
{
	t_star	*start;

	start = (t_star *)malloc(sizeof(*start));
	(*start).f = 0;
	(*start).g = 0;
	(*start).h = 0;
	ft_stackadd_top(stack, ft_newnode(start));
}

void	a_star_pathfinding(void)
{
	t_stack	*open_lst;
	t_stack	*close_lst;
	t_star	*end;

	/*
	end = (t_star *)malloc(sizeof(*end));
	(*end).f = 0;
	(*end).g = 0;
	(*end).h = 0;
	*/
	open_lst = ft_stacknew();
	close_lst = ft_stacknew();
	ft_stack_init(open_lst);

//	ft_stackclear(open_lst);
//	ft_stackclear(close_lst);
}
