/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:52:36 by faventur          #+#    #+#             */
/*   Updated: 2022/04/27 16:33:34 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

int	verify_conditions(char **map)
{
	t_vector	candy_pos;

	candy_pos = ft_get_x_and_y(map, 'C');
	if (candy_pos.x < 0)
		return (1);
	else
		return (0);
}

void	move_ur_ass(char **map)
{
	t_vector	d_pos;
	t_vector	e_pos;
	t_vector	c_pos;

	d_pos = ft_get_x_and_y(map, 'K');
	e_pos = ft_get_x_and_y(map, 'E');
	c_pos = ft_get_x_and_y(map, 'P');
	if (c_pos.x == -1)
		c_pos = ft_get_x_and_y(map, 'L');
	if (c_pos.x == -1)
		c_pos = ft_get_x_and_y(map, 'F');
	if (c_pos.x == -1)
		c_pos = ft_get_x_and_y(map, 'B');
	if (d_pos.x > e_pos.x)
	{
		if (map[d_pos.y][d_pos.x - 1] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y][d_pos.x - 1] == 'E')
				exit(0);
			map[d_pos.y][d_pos.x - 1] = 'K';
		}
		else if (map[d_pos.y + 1][d_pos.x] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y + 1][d_pos.x] == 'E')
				exit(0);
			map[d_pos.y + 1][d_pos.x] = 'K';
		}
		else if (map[d_pos.y - 1][d_pos.x] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y - 1][d_pos.x] == 'E')
				exit(0);
			map[d_pos.y - 1][d_pos.x] = 'K';
		}
		else if (map[d_pos.y][d_pos.x + 1] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y][d_pos.x + 1] == 'E')
				exit(0);
			map[d_pos.y][d_pos.x + 1] = 'K';
		}
	}
	else if (d_pos.x < e_pos.x)
	{
		if (map[d_pos.y][d_pos.x + 1] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y][d_pos.x + 1] == 'E')
				exit(0);
			map[d_pos.y][d_pos.x + 1] = 'K';
		}
		else if (map[d_pos.y + 1][d_pos.x] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y + 1][d_pos.x] == 'E')
				exit(0);
			map[d_pos.y + 1][d_pos.x] = 'K';
		}
		else if (map[d_pos.y][d_pos.x - 1] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y][d_pos.x - 1] == 'E')
				exit(0);
			map[d_pos.y][d_pos.x - 1] = 'K';
		}
		else if (map[d_pos.y - 1][d_pos.x] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y - 1][d_pos.x] == 'E')
				exit(0);
			map[d_pos.y - 1][d_pos.x] = 'K';
		}
	}
	else if (d_pos.y < e_pos.y)
	{
		if (map[d_pos.y + 1][d_pos.x] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y + 1][d_pos.x] == 'E')
				exit(0);
			map[d_pos.y + 1][d_pos.x] = 'K';
		}
		else if (map[d_pos.y - 1][d_pos.x] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y - 1][d_pos.x] == 'E')
				exit(0);
			map[d_pos.y - 1][d_pos.x] = 'K';
		}
		else if (map[d_pos.y][d_pos.x + 1] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y][d_pos.x + 1] == 'E')
				exit(0);
			map[d_pos.y][d_pos.x + 1] = 'K';
		}
		else if (map[d_pos.y][d_pos.x - 1] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y][d_pos.x - 1] == 'E')
				exit(0);
			map[d_pos.y][d_pos.x - 1] = 'K';
		}
	}
	else if (d_pos.y > e_pos.y)
	{
		if (map[d_pos.y - 1][d_pos.x] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y - 1][d_pos.x] == 'E')
				exit(0);
			map[d_pos.y - 1][d_pos.x] = 'K';
		}
		else if (map[d_pos.y][d_pos.x + 1] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y][d_pos.x + 1] == 'E')
				exit(0);
			map[d_pos.y][d_pos.x + 1] = 'K';
		}
		else if (map[d_pos.y][d_pos.x - 1] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y][d_pos.x - 1] == 'E')
				exit(0);
			map[d_pos.y][d_pos.x - 1] = 'K';
		}
		else if (map[d_pos.y + 1][d_pos.x] != '1')
		{
			map[d_pos.y][d_pos.x] = '0';
			if (map[d_pos.y + 1][d_pos.x] == 'E')
				exit(0);
			map[d_pos.y + 1][d_pos.x] = 'K';
		}
	}
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
	if (key == 125 && map[pos.y + 1][pos.x] != '1'
		&& map[pos.y - 1][pos.x] != 'E')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y + 1][pos.x] == 'C' || map[pos.y + 1][pos.x] == '0')
			map[pos.y + 1][pos.x] = 'F';
		if (map[pos.y + 1][pos.x] == 'E' && verify_conditions(map))
			exit(0);
	}
	else if (key == 126 && map[pos.y - 1][pos.x] != '1'
		&& map[pos.y + 1][pos.x] != 'E')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y - 1][pos.x] == 'C' || map[pos.y - 1][pos.x] == '0')
			map[pos.y - 1][pos.x] = 'B';
		if (map[pos.y - 1][pos.x] == 'E' && verify_conditions(map))
			exit(0);
	}
	else if (key == 53)
		exit(0);
}

t_vector	get_char_pos(char **map)
{
	t_vector	pos;

	pos = ft_get_x_and_y(map, 'P');
	if (pos.x == -1)
		pos = ft_get_x_and_y(map, 'L');
	if (pos.x == -1)
		pos = ft_get_x_and_y(map, 'F');
	if (pos.x == -1)
		pos = ft_get_x_and_y(map, 'B');
	return (pos);
}

void	ft_display_moves(char **map, int key)
{
	t_vector	pos;

	pos = get_char_pos(map);
	if (key == 123 && map[pos.y][pos.x - 1] != '1'
		&& map[pos.y][pos.x - 1] != 'E')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x - 1] == 'C' || map[pos.y][pos.x - 1] == '0')
			map[pos.y][pos.x - 1] = 'L';
		if (map[pos.y][pos.x - 1] == 'E' && verify_conditions(map))
			exit(0);
	}
	else if (key == 124 && map[pos.y][pos.x + 1] != '1'
		&& map[pos.y][pos.x + 1] != 'E')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x + 1] == 'C' || map[pos.y][pos.x + 1] == '0')
			map[pos.y][pos.x + 1] = 'P';
		if (map[pos.y][pos.x + 1] == 'E' && verify_conditions(map))
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
	ft_printf("Key pressed -> %d\n", key);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program;
	static int	frame;
	t_vector	pos;

	program = (t_program *)param;
	pos = ft_get_coordinates(program->map, 'P');
	frame++;
	if (frame == ANIMATION_FRAMES)
		pos.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		pos.y -= 1;
		frame = 0;
	}
//	mlx_put_image_to_window(program->mlx, program->window.reference,
//		program->pixies[4].reference, pos.x, pos.y);
	ft_printf("input %d, %d\n", pos.x, pos.y);
	return (0);
}
