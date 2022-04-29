/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:19:01 by faventur          #+#    #+#             */
/*   Updated: 2022/04/29 19:44:09 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_STAR_H
# define A_STAR_H

# include "stacks.h"
# include "mlx_utils.h"

typedef struct s_star
{
	int				g;
	int				h;
	int				f;
	t_vector		index;
}					t_star;



#endif