/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:52:36 by faventur          #+#    #+#             */
/*   Updated: 2022/04/16 11:44:53 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	mlx_clear_window(program->mlx, program->window.reference);
	ft_put_background(*program, "images/chessboard.xpm");
	if (key == 124)
		program->sprite_position.x += program->sprite.size.x;
	else if (key == 123)
		program->sprite_position.x -= program->sprite.size.x;
	else if (key == 125)
		program->sprite_position.y += program->sprite.size.y;
	else if (key == 126)
		program->sprite_position.y -= program->sprite.size.y;
	else if (key == 15)
		turn_img_to_color(&program->sprite, new_color(255, 0, 0, 0));
	else if (key == 5)
		turn_img_to_color(&program->sprite, new_color(0, 255, 0, 0));
	else if (key == 11)
		turn_img_to_color(&program->sprite, new_color(0, 0, 255, 0));
	mlx_put_image_to_window(program->mlx, program->window.reference,
		program->sprite.reference, program->sprite_position.x,
		program->sprite_position.y);
	ft_printf("Key pressed -> %d\n", key);
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
