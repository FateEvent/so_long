/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:44:41 by faventur          #+#    #+#             */
/*   Updated: 2022/05/08 15:32:55 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	track_ur_move_up(t_program *data, t_nme death)
{
	if (data->map[death.pos.y - 1][death.pos.x] != '1'
			&& data->map[death.pos.y - 1][death.pos.x] != 'C'
			&& data->map[death.pos.y - 1][death.pos.x] != 'E')
	{
		data->map[death.pos.y][death.pos.x] = '0';
		if (data->map[death.pos.y - 1][death.pos.x] == who_is_it(data->map))
			exit(0);
		data->map[death.pos.y - 1][death.pos.x] = 'K';
	}
	else if (data->map[death.pos.y][death.pos.x + 1] != '1'
			&& data->map[death.pos.y][death.pos.x + 1] != 'C'
			&& data->map[death.pos.y][death.pos.x + 1] != 'E')
	{
		data->map[death.pos.y][death.pos.x] = '0';
		if (data->map[death.pos.y][death.pos.x + 1] == who_is_it(data->map))
			exit(0);
		data->map[death.pos.y][death.pos.x + 1] = 'K';
	}
}

void	track_ur_move_left(t_program *data, t_nme death)
{
	if (data->map[death.pos.y][death.pos.x - 1] != '1'
			&& data->map[death.pos.y][death.pos.x - 1] != 'C'
			&& data->map[death.pos.y][death.pos.x - 1] != 'E')
	{
		data->map[death.pos.y][death.pos.x] = '0';
		if (data->map[death.pos.y][death.pos.x - 1] == who_is_it(data->map))
			exit(0);
		data->map[death.pos.y][death.pos.x - 1] = 'K';
	}
	else if (data->map[death.pos.y + 1][death.pos.x] != '1'
			&& data->map[death.pos.y + 1][death.pos.x] != 'C'
			&& data->map[death.pos.y + 1][death.pos.x] != 'E')
	{
		data->map[death.pos.y][death.pos.x] = '0';
		if (data->map[death.pos.y + 1][death.pos.x] == who_is_it(data->map))
			exit(0);
		data->map[death.pos.y + 1][death.pos.x] = 'K';
	}
}

void	move_ur_ass(t_program *data)
{
	t_vector	e_pos;
	t_vector	c_pos;
	t_nme		death;

	death.pos = ft_get_x_and_y(data->map, 'K');
	e_pos = ft_get_x_and_y(data->map, 'E');
	c_pos = ft_get_char_pos(data->map);
	if (death.pos.x > e_pos.x)
		track_ur_move_left(data, death);
	else if (death.pos.y > e_pos.y)
		track_ur_move_up(data, death);
	else if (death.pos.x < e_pos.x)
		track_ur_move_right(data, death);
	else if (death.pos.y < e_pos.y)
		track_ur_move_down(data, death);
}
