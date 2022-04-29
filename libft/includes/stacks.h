/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:10:47 by faventur          #+#    #+#             */
/*   Updated: 2022/04/29 14:26:36 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

# include "libft.h"

typedef struct s_node
{
	int				content;
	int				index;
	struct s_node	*prev;
	struct s_node	*next;
}					t_node;

typedef struct s_stack
{
	size_t			length;
	struct s_node	*top;
	struct s_node	*bottom;
}					t_stack;

// Doubly linked list functions
t_stack	*ft_stacknew(void);
t_node	*ft_newnode(int content);
t_stack	*ft_stackadd_top(t_stack *stack, t_node *new);
t_stack	*ft_stackadd_bottom(t_stack *stack, t_node *new);
t_stack	*ft_stackinsert(t_stack *stack, t_node *node, int position);
void	ft_stackclear(t_stack **stack);
int		ft_stacksize(t_stack *stack);
void	ft_stackdisplay(t_stack *stack);
void	ft_displayindex(t_stack *stack);

void	ft_stack_init(int argc, char *argv[], t_stack *stack);
void	ft_assign_index(t_stack *stack);

#endif