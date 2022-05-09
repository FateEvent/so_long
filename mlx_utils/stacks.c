/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:12:14 by faventur          #+#    #+#             */
/*   Updated: 2022/05/09 16:50:47 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "a_star.h"

void	ft_stack_init(t_stack *stack, char **map)
{
	t_star	*start;

	start = (t_star *)malloc(sizeof(*start));
	(*start).f = 0;
	(*start).g = 0;
	(*start).h = 0;
	(*start).pos = ft_get_x_and_y(map, "K");
	ft_stackadd_top(stack, ft_newnode(start));
}

void	a_star_pathfinding(char **map)
{
	t_stack	*open_lst;
	t_stack	*close_lst;
	t_node	*current;
	t_star	*end;

	end = (t_star *)malloc(sizeof(*end));
	(*end).f = 0;
	(*end).g = 0;
	(*end).h = 0;
	(*end).pos = ft_get_x_and_y(map, "E");
	open_lst = ft_stacknew();
	close_lst = ft_stacknew();
	ft_stack_init(open_lst, map);
	current = open_lst->top;
/*
	while (current->content->pos.x != end->pos.x && current->content->pos.y != end->pos.y)
//	ft_stackclear(open_lst);
//	ft_stackclear(close_lst);
*/
}
