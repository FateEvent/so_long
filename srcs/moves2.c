/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:44:41 by faventur          #+#    #+#             */
/*   Updated: 2022/05/02 20:12:49 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	you_lose(t_program data)
{
	ft_display_map(data, data.map, data.pixies);
	mlx_string_put(data.mlx, data.window.reference, 10, 44,
		0xff000000, "You lose!");
}

static void	track_ur_move_down_pt2(t_program data, t_nme death)
{
	if (data.map[death.pos.y][death.pos.x + 1] != '1'
			&& data.map[death.pos.y][death.pos.x + 1] != 'C'
			&& death.pos.x + 1 != death.prev.x)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y][death.pos.x + 1] == 'E'
			|| data.map[death.pos.y][death.pos.x + 1] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
		data.map[death.pos.y][death.pos.x + 1] = 'K';
	}
	else if (data.map[death.pos.y - 1][death.pos.x] != '1'
			&& data.map[death.pos.y - 1][death.pos.x] != 'C'
			&& death.pos.y - 1 != death.prev.y)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y - 1][death.pos.x] == 'E'
			|| data.map[death.pos.y - 1][death.pos.x] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
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
		if (data.map[death.pos.y + 1][death.pos.x] == 'E'
			|| data.map[death.pos.y + 1][death.pos.x] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
		data.map[death.pos.y + 1][death.pos.x] = 'K';
	}
	else if (data.map[death.pos.y][death.pos.x - 1] != '1'
			&& data.map[death.pos.y][death.pos.x - 1] != 'C'
			&& death.pos.x - 1 != death.prev.x)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y - 1][death.pos.x] == 'E'
			|| data.map[death.pos.y - 1][death.pos.x] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
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
		if (data.map[death.pos.y - 1][death.pos.x] == 'E'
			|| data.map[death.pos.y - 1][death.pos.x] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
		data.map[death.pos.y][death.pos.x - 1] = 'K';
	}
	else if (data.map[death.pos.y - 1][death.pos.x] != '1'
			&& data.map[death.pos.y - 1][death.pos.x] != 'C'
			&& death.pos.y - 1 != death.prev.y)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y - 1][death.pos.x] == 'E'
			|| data.map[death.pos.y - 1][death.pos.x] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
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
		if (data.map[death.pos.y][death.pos.x + 1] == 'E'
			|| data.map[death.pos.y][death.pos.x + 1] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
		data.map[death.pos.y][death.pos.x + 1] = 'K';
	}
	else if (data.map[death.pos.y + 1][death.pos.x] != '1'
			&& data.map[death.pos.y + 1][death.pos.x] != 'C'
			&& death.pos.y + 1 != death.prev.y)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y + 1][death.pos.x] == 'E'
			|| data.map[death.pos.y + 1][death.pos.x] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
		data.map[death.pos.y + 1][death.pos.x] = 'K';
	}
	else
		track_ur_move_right_pt2(data, death);
}
