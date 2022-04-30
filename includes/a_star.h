/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_star.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 19:19:01 by faventur          #+#    #+#             */
/*   Updated: 2022/04/30 12:16:50 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef A_STAR_H
# define A_STAR_H

# include "stacks.h"
# include "mlx_utils.h"

typedef struct s_star
{
	int				f;
	int				g;
	int				h;
	t_vector		pos;
}					t_star;

#endif