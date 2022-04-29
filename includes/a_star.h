/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:19:01 by faventur          #+#    #+#             */
/*   Updated: 2022/04/29 19:39:34 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_STAR_H
# define A_STAR_H

# include "stacks.h"
# include "mlx_utils.h"

typedef struct s_node
{
	int				g;
	int				h;
	int				f;
	int				index;
}					t_node;

// Doubly linked list functions
t_stack	*ft_stacknew(void);
t_stack	*ft_stackadd_top(t_stack *stack, t_node *new);
t_stack	*ft_stackadd_bottom(t_stack *stack, t_node *new);
t_stack	*ft_stackinsert(t_stack *stack, t_node *node, int position);
t_node	*ft_newnode(int content);
void	ft_stack_init(int argc, char *argv[], t_stack *stack);
void	ft_stackclear(t_stack **stack);
void	ft_stackdisplay(t_stack *stack);
void	ft_stackdisplay(t_stack *stack);
void	ft_assign_index(t_stack *stack);
void	ft_displayindex(t_stack *stack);
int		ft_stacksize(t_stack *stack);

#endif