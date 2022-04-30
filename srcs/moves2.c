/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:44:41 by faventur          #+#    #+#             */
/*   Updated: 2022/04/30 19:52:32 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

static void	track_ur_move_down_pt2(t_program data, t_nme death)
{
	if (data.map[death.pos.y][death.pos.x + 1] != '1'
			&& data.map[death.pos.y][death.pos.x + 1] != 'C'
			&& death.pos.x + 1 != death.prev.x)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y][death.pos.x + 1] == 'E')
			exit(0);
		data.map[death.pos.y][death.pos.x + 1] = 'K';
	}
	else if (data.map[death.pos.y - 1][death.pos.x] != '1'
			&& data.map[death.pos.y - 1][death.pos.x] != 'C'
			&& death.pos.y - 1 != death.prev.y)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y - 1][death.pos.x] == 'E')
			exit(0);
		data.map[death.pos.y - 1][death.pos.x] = 'K';
	}
}

void	track_ur_move_down(t_program data, t_nme death)
{
	if (data.map[death.pos.y + 1][death.pos.x] != '1'
			&& data.map[death.pos.y + 1][death.pos.x] != 'C'
			&& death.pos.y + 1 != death.prev.y)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y + 1][death.pos.x] == 'E')
			exit(0);
		data.map[death.pos.y + 1][death.pos.x] = 'K';
	}
	else if (data.map[death.pos.y][death.pos.x - 1] != '1'
			&& data.map[death.pos.y][death.pos.x - 1] != 'C'
			&& death.pos.x - 1 != death.prev.x)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y - 1][death.pos.x] == 'E')
			exit(0);
		data.map[death.pos.y][death.pos.x - 1] = 'K';
	}
	else
		track_ur_move_down_pt2(data, death);
}

static void	track_ur_move_right_pt2(t_program data, t_nme death)
{
	if (data.map[death.pos.y][death.pos.x - 1] != '1'
			&& data.map[death.pos.y][death.pos.x - 1] != 'C'
			&& death.pos.x - 1 != death.prev.x)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y - 1][death.pos.x] == 'E')
			exit(0);
		data.map[death.pos.y][death.pos.x - 1] = 'K';
	}
	else if (data.map[death.pos.y - 1][death.pos.x] != '1'
			&& data.map[death.pos.y - 1][death.pos.x] != 'C'
			&& death.pos.y - 1 != death.prev.y)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y - 1][death.pos.x] == 'E')
			exit(0);
		data.map[death.pos.y - 1][death.pos.x] = 'K';
	}
}

void	track_ur_move_right(t_program data, t_nme death)
{
	if (data.map[death.pos.y][death.pos.x + 1] != '1'
			&& data.map[death.pos.y][death.pos.x + 1] != 'C'
			&& death.pos.x + 1 != death.prev.x)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y][death.pos.x + 1] == 'E')
			exit(0);
		data.map[death.pos.y][death.pos.x + 1] = 'K';
	}
	else if (data.map[death.pos.y + 1][death.pos.x] != '1'
			&& data.map[death.pos.y + 1][death.pos.x] != 'C'
			&& death.pos.y + 1 != death.prev.y)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y + 1][death.pos.x] == 'E')
			exit(0);
		data.map[death.pos.y + 1][death.pos.x] = 'K';
	}
	else
		track_ur_move_right_pt2(data, death);
}
