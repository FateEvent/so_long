/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:52:36 by faventur          #+#    #+#             */
/*   Updated: 2022/04/25 19:19:04 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"
/*
void	ft_map_rewriter(t_vector position, char **map)
{
	t_vector	coord;

	coord = position;
	if (map[coord.x / 65][coord.y / 65]
		&& map[coord.x / 65][coord.y / 65] != '0')
	{
		map[coord.x / 65][coord.y / 65] = '0';
		ft_printf("coord %d, %d\n", coord.x / 65, coord.y / 65);
	}
}
*/
int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	mlx_clear_window(program->mlx, program->window.reference);
	ft_display_map(*program, (*program).map, (*program).pixies);
	if (key == 124)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 123)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 125)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 126)
		program->sprite_position.y -= program->sprite.size.y;
	else if (key == 53)
		exit(0);
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x,
		program->sprite_position.y);
	ft_printf("Key pressed -> %d\n", key);
	ft_printf("coord -> %d, %d\n", program->sprite_position.x, program->sprite_position.y);
//	ft_map_rewriter((*program).sprite_position, (*program).map);
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
