/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 14:44:41 by faventur          #+#    #+#             */
/*   Updated: 2022/04/30 14:58:32 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

static void	track_ur_move_down(char **map, t_vector pos)
{
	if (map[pos.y + 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y + 1][pos.x] == 'E')
			exit(0);
		map[pos.y + 1][pos.x] = 'K';
	}
	else if (map[pos.y][pos.x - 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x - 1] == 'E')
			exit(0);
		map[pos.y][pos.x - 1] = 'K';
	}
	else if (map[pos.y][pos.x + 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x + 1] == 'E')
			exit(0);
		map[pos.y][pos.x + 1] = 'K';
	}
	else if (map[pos.y - 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y - 1][pos.x] == 'E')
			exit(0);
		map[pos.y - 1][pos.x] = 'K';
	}
}

static void	track_ur_move_right(char **map, t_vector pos)
{
	if (map[pos.y][pos.x + 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x + 1] == 'E')
			exit(0);
		map[pos.y][pos.x + 1] = 'K';
	}
	else if (map[pos.y + 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y + 1][pos.x] == 'E')
			exit(0);
		map[pos.y + 1][pos.x] = 'K';
	}
	else if (map[pos.y][pos.x - 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x - 1] == 'E')
			exit(0);
		map[pos.y][pos.x - 1] = 'K';
	}
	else if (map[pos.y - 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y - 1][pos.x] == 'E')
			exit(0);
		map[pos.y - 1][pos.x] = 'K';
	}
}

static void	track_ur_move_up(char **map, t_vector pos)
{
	if (map[pos.y - 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y - 1][pos.x] == 'E')
			exit(0);
		map[pos.y - 1][pos.x] = 'K';
	}
	else if (map[pos.y][pos.x + 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x + 1] == 'E')
			exit(0);
		map[pos.y][pos.x + 1] = 'K';
	}
	else if (map[pos.y + 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y + 1][pos.x] == 'E')
			exit(0);
		map[pos.y + 1][pos.x] = 'K';
	}
	else if (map[pos.y][pos.x - 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x - 1] == 'E')
			exit(0);
		map[pos.y][pos.x - 1] = 'K';
	}
}

static void	track_ur_move_left(char **map, t_vector pos)
{
	if (map[pos.y][pos.x - 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x - 1] == 'E')
			exit(0);
		map[pos.y][pos.x - 1] = 'K';
	}
	else if (map[pos.y + 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y + 1][pos.x] == 'E')
			exit(0);
		map[pos.y + 1][pos.x] = 'K';
	}
	else if (map[pos.y - 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y - 1][pos.x] == 'E')
			exit(0);
		map[pos.y - 1][pos.x] = 'K';
	}
	else if (map[pos.y][pos.x + 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x + 1] == 'E')
			exit(0);
		map[pos.y][pos.x + 1] = 'K';
	}
}

void	move_ur_ass(char **map)
{
	t_vector	d_pos;
	t_vector	e_pos;
	t_vector	c_pos;

	d_pos = ft_get_x_and_y(map, 'K');
	e_pos = ft_get_x_and_y(map, 'E');
	c_pos = ft_get_char_pos(map);
	if (d_pos.x > e_pos.x)
		track_ur_move_left(map, d_pos);
	else if (d_pos.y > e_pos.y)
		track_ur_move_up(map, d_pos);
	else if (d_pos.x <= e_pos.x)
		track_ur_move_right(map, d_pos);
	else if (d_pos.y <= e_pos.y)
		track_ur_move_down(map, d_pos);
}
