/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:52:36 by faventur          #+#    #+#             */
/*   Updated: 2022/04/27 12:41:06 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
/*
void	ft_subtract(int a, int b)
{
	
}
*/
void	move_ur_ass(char **map)
{
	t_vector	d_pos;
	t_vector	e_pos;
//	t_vector	c_pos;

	d_pos = ft_get_x_and_y(map, 'K');
	e_pos = ft_get_x_and_y(map, 'E');
/*
	c_pos = ft_get_x_and_y(map, 'P');
	if (c_pos.x == -1)
		c_pos = ft_get_x_and_y(map, 'L');
	if (c_pos.x == -1)
		c_pos = ft_get_x_and_y(map, 'F');
	if (c_pos.x == -1)
		c_pos = ft_get_x_and_y(map, 'B');
*/
	if (d_pos.x > e_pos.x)
	{
		map[d_pos.y][d_pos.x] = '0';
		map[d_pos.y][d_pos.x - 1] = 'K';
	}
	else if (d_pos.x < e_pos.x)
	{
		map[d_pos.y][d_pos.x] = '0';
		map[d_pos.y][d_pos.x + 1] = 'K';
	}
	else if (d_pos.y < e_pos.y)
	{
		map[d_pos.y][d_pos.x] = '0';
		map[d_pos.y + 1][d_pos.x] = 'K';
	}
	else if (d_pos.y > e_pos.y)
	{
		map[d_pos.y][d_pos.x] = '0';
		map[d_pos.y - 1][d_pos.x] = 'K';
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
	if (key == 125 && map[pos.y + 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y + 1][pos.x] == 'E')
			exit(0);
		map[pos.y + 1][pos.x] = 'F';
	}
	else if (key == 126 && map[pos.y - 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y - 1][pos.x] == 'E')
			exit(0);
		map[pos.y - 1][pos.x] = 'B';
	}
	else if (key == 53)
		exit(0);
}

void	ft_display_moves(char **map, int key)
{
	t_vector	pos;

	pos = ft_get_x_and_y(map, 'P');
	if (pos.x == -1)
		pos = ft_get_x_and_y(map, 'L');
	if (pos.x == -1)
		pos = ft_get_x_and_y(map, 'F');
	if (pos.x == -1)
		pos = ft_get_x_and_y(map, 'B');
	if (key == 123 && map[pos.y][pos.x - 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x - 1] == 'E')
			exit(0);
		map[pos.y][pos.x - 1] = 'L';
	}
	else if (key == 124 && map[pos.y][pos.x + 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		if (map[pos.y][pos.x + 1] == 'E')
			exit(0);
		map[pos.y][pos.x + 1] = 'P';
	}
	ft_display_moves_pt2(pos, map, key);
	ft_printf("%d, %d %c\n", pos.x, pos.y, map[pos.y][pos.x]);
}

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	ft_display_moves(program->map, key);
	mlx_clear_window(program->mlx, program->window.reference);
	ft_display_map(*program, (*program).map, (*program).pixies);
	move_ur_ass((*program).map);
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
