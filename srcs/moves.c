/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:44:41 by faventur          #+#    #+#             */
/*   Updated: 2022/05/02 20:13:00 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

static void	track_ur_move_up_pt2(t_program data, t_nme death)
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
}

void	track_ur_move_up(t_program data, t_nme death)
{
	if (data.map[death.pos.y - 1][death.pos.x] != '1'
			&& data.map[death.pos.y - 1][death.pos.x] != 'C'
			&& death.pos.y - 1 != death.prev.y)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y - 1][death.pos.x] == 'E'
			|| data.map[death.pos.y - 1][death.pos.x] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
		data.map[death.pos.y - 1][death.pos.x] = 'K';
	}
	else if (data.map[death.pos.y][death.pos.x + 1] != '1'
			&& data.map[death.pos.y][death.pos.x + 1] != 'C'
			&& death.pos.x + 1 != death.prev.x)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y][death.pos.x + 1] == 'E'
			|| data.map[death.pos.y][death.pos.x + 1] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
		data.map[death.pos.y][death.pos.x + 1] = 'K';
	}
	else
		track_ur_move_up_pt2(data, death);
}

static void	track_ur_move_left_pt2(t_program data, t_nme death)
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

void	track_ur_move_left(t_program data, t_nme death)
{
	if (data.map[death.pos.y][death.pos.x - 1] != '1'
			&& data.map[death.pos.y][death.pos.x - 1] != 'C'
			&& death.pos.x - 1 != death.prev.x)
	{
		data.map[death.pos.y][death.pos.x] = '0';
		if (data.map[death.pos.y][death.pos.x - 1] == 'E'
			|| data.map[death.pos.y][death.pos.x - 1] == who_is_it(data.map))
			mlx_destroy_window(data.mlx, data.window.reference);
		data.map[death.pos.y][death.pos.x - 1] = 'K';
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
		track_ur_move_left_pt2(data, death);
}

void	move_ur_ass(t_program data)
{
	t_vector	e_pos;
	t_vector	c_pos;
	t_nme		death;

	death.pos = ft_get_x_and_y(data.map, 'K');
	e_pos = ft_get_x_and_y(data.map, 'E');
	c_pos = ft_get_char_pos(data.map);
	if (death.pos.x > e_pos.x)
		track_ur_move_left(data, death);
	else if (death.pos.y > e_pos.y)
		track_ur_move_up(data, death);
	else if (death.pos.x < e_pos.x)
		track_ur_move_right(data, death);
	else if (death.pos.y < e_pos.y)
		track_ur_move_down(data, death);
	death.prev = death.pos;
}

/*
void boucle(t_program data)
{
	t_vector	start;
	int			i;
	int			j;

	i = 5;
	j = 3;
	start = ft_get_x_and_y(data.map, 'K');
	while(start.x < start.x + i)
	{
		data.map[start.y][start.x] = '0';
		data.map[start.y][start.x + 1] = 'K';
		start.x++;
		i--;
	}
	while(start.y < start.y + j)
	{
		data.map[start.y][start.x] = '0';
		data.map[start.y + j][start.x] = 'K';
		start.y++;
		j--;
	}
	while(start.x > start.x - i)
	{
		data.map[start.y][start.x] = '0';
		data.map[start.y][start.x - 1] = '0';
		start.x--;
		i++;
	}
	while(start.y > start.y - j)
	{
		data.map[start.y][start.x] = '0';
		data.map[start.y - j][start.x] = 'K';
		start.y++;
		j++;
	}
}
*/