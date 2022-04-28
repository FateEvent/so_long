/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:52:36 by faventur          #+#    #+#             */
/*   Updated: 2022/04/28 17:58:50 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
#include <math.h>

int	verify_conditions(char **map)
{
	t_vector	candy_pos;

	candy_pos = ft_get_x_and_y(map, 'C');
	if (candy_pos.x < 0)
		return (1);
	else
		return (0);
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
	else if (d_pos.x < e_pos.x)
		track_ur_move_right(map, d_pos);
	else if (d_pos.y < e_pos.y)
		track_ur_move_down(map, d_pos);
}

void	ft_map_rewriter(int y, int x, char **map)
{
	if (map[y / 63][x / 63]
		&& map[y / 63][x / 63] == 'C')
	{
		map[y / 63][x / 63] = '0';
		ft_printf("pos %d, %d\n", x / 63, y / 63);
	}
}

void	ft_display_moves_pt2(t_vector pos, char **map, int key)
{
	if (key == 125 && map[pos.y + 1][pos.x] != '1')
	{
		if (map[pos.y + 1][pos.x] == 'C' || map[pos.y + 1][pos.x] == '0')
		{
			map[pos.y][pos.x] = '0';
			map[pos.y + 1][pos.x] = 'F';
		}
		else if (map[pos.y + 1][pos.x] == 'E' && verify_conditions(map))
			exit(0);
	}
	else if (key == 126 && map[pos.y - 1][pos.x] != '1')
	{
		if (map[pos.y - 1][pos.x] == 'C' || map[pos.y - 1][pos.x] == '0')
		{
			map[pos.y][pos.x] = '0';
			map[pos.y - 1][pos.x] = 'B';
		}
		else if (map[pos.y - 1][pos.x] == 'E' && verify_conditions(map))
			exit(0);
	}
	else if (key == 53)
		exit(0);
}

void	ft_display_moves(char **map, int key)
{
	t_vector	pos;

	pos = ft_get_char_pos(map);
	if (key == 123 && map[pos.y][pos.x - 1] != '1')
	{
		if (map[pos.y][pos.x - 1] == 'C' || map[pos.y][pos.x - 1] == '0')
		{
			map[pos.y][pos.x] = '0';
			map[pos.y][pos.x - 1] = 'L';
		}
		else if (map[pos.y][pos.x - 1] == 'E' && verify_conditions(map))
			exit(0);
	}
	else if (key == 124 && map[pos.y][pos.x + 1] != '1')
	{
		if (map[pos.y][pos.x + 1] == 'C' || map[pos.y][pos.x + 1] == '0')
		{
			map[pos.y][pos.x] = '0';
			map[pos.y][pos.x + 1] = 'P';
		}
		else if (map[pos.y][pos.x + 1] == 'E' && verify_conditions(map))
			exit(0);
	}
	else
		ft_display_moves_pt2(pos, map, key);
}

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	ft_display_moves(program->map, key);
	move_ur_ass((*program).map);
	mlx_clear_window(program->mlx, program->window.reference);
	ft_display_map(*program, (*program).map, (*program).pixies);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program;
	t_vector	basic_pos[2];
	t_vector	var;

	program = (t_program *)param;
	basic_pos[0] = ft_get_char_pos((*program).map);
	basic_pos[1] = ft_get_x_and_y((*program).map, 'K');
	var.x = sin(program->frame / 20) * 2;
	var.y = sin(program->frame / 13) * 2;
	program->frame++;
	ft_invoke_char(*program, (*program).pixies, basic_pos[0], var.x);
	ft_invoke_enemy(*program, (*program).pixies, basic_pos[1], var.y);
	return (0);
}
