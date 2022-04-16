/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 14:46:30 by faventur          #+#    #+#             */
/*   Updated: 2022/04/16 13:38:47 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/mlx_utils.h"

void	prop_init(t_prop *obj)
{
	obj->item = 0;
	obj->exit = 0;
	obj->start_pos = 0;
}
