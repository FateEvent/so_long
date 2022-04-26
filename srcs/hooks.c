/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:52:36 by faventur          #+#    #+#             */
/*   Updated: 2022/04/26 20:33:26 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	ft_map_rewriter(int y, int x, char **map)
{
	if (map[y / 63][x / 63]
		&& map[y / 63][x / 63] == 'C')
	{
		map[y / 63][x / 63] = '0';
		ft_printf("pos %d, %d\n", x / 63, y / 63);
	}
}

void	ft_display_moves(char **map, int key)
{
	t_vector	pos;

	pos = ft_get_x_and_y(map, 'P');
	if (key == 123 && map[pos.y][pos.x - 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		map[pos.y][pos.x - 1] = 'P';
	}
	else if (key == 124 && map[pos.y][pos.x + 1] != '1')
	{
		map[pos.y][pos.x] = '0';
		map[pos.y][pos.x + 1] = 'P';
	}
	else if (key == 125 && map[pos.y + 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		map[pos.y + 1][pos.x] = 'P';
	}
	else if (key == 126 && map[pos.y - 1][pos.x] != '1')
	{
		map[pos.y][pos.x] = '0';
		map[pos.y - 1][pos.x] = 'P';
	}
	else if (key == 53)
		exit(0);
	ft_printf("%d, %d %c\n", pos.x, pos.y, map[pos.y][pos.x]);
}

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	mlx_clear_window(program->mlx, program->window.reference);
	ft_display_map(*program, (*program).map, (*program).pixies);
	if (key == 124 && (*program).map[program->sprite_position.y / 63][(program->sprite_position.x + program->sprite.size.x) / 63] != '1')
	{
		ft_map_rewriter(program->sprite_position.y, program->sprite_position.x + program->sprite.size.x, program->map);
		ft_display_moves(program->map, key);
//		program->sprite_position.x += program->sprite.size.x;
	}
	else if (key == 123 && (*program).map[program->sprite_position.y / 63][(program->sprite_position.x - program->sprite.size.x) / 63] != '1')
	{
		ft_map_rewriter(program->sprite_position.y, program->sprite_position.x - program->sprite.size.x, program->map);
		ft_display_moves(program->map, key);
//		program->sprite_position.x -= program->sprite.size.x;
	}
	else if (key == 125 && (*program).map[(program->sprite_position.y + program->sprite.size.y) / 63][program->sprite_position.x / 63] != '1')
	{
		ft_map_rewriter(program->sprite_position.y + program->sprite.size.y, program->sprite_position.x, program->map);
		ft_display_moves(program->map, key);
//		program->sprite_position.y += program->sprite.size.y;
	}
	else if (key == 126 && (*program).map[(program->sprite_position.y - program->sprite.size.y) / 63][program->sprite_position.x / 63] != '1')
	{
		ft_map_rewriter(program->sprite_position.y - program->sprite.size.y, program->sprite_position.x, program->map);
		ft_display_moves(program->map, key);
//		program->sprite_position.y -= program->sprite.size.y;
	}
	else if (key == 53)
		exit(0);
//	mlx_put_image_to_window(program->mlx, program->window.reference,
//		program->sprite.reference, program->sprite_position.x,
//		program->sprite_position.y);
	ft_printf("Key pressed -> %d\n", key);
	ft_printf("coord -> %d, %d\n", program->sprite_position.x / 63, program->sprite_position.y / 63);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program;
	static int	frame;

	program = (t_program *)param;
	frame++;
	if (frame == ANIMATION_FRAMES)
		program->sprite_position.y += 1;
	else if (frame >= ANIMATION_FRAMES * 2)
	{
		program->sprite_position.y -= 1;
		frame = 0;
	}
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x,
		program->sprite_position.y);
	return (0);
}
