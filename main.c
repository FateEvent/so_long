/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:13:32 by faventur          #+#    #+#             */
/*   Updated: 2022/04/02 19:17:47 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(void)
{
	t_program	program;

	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 1980, 1080, "Hello world!");
	ft_put_background(program, "images/chessboard.xpm");
	program.sprite = ft_new_sprite(program.mlx, "images/befana_giant.xpm");
	program.sprite_position.x = 0;
	program.sprite_position.y = 0;
	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x,
		program.sprite_position.y);
	mlx_key_hook(program.window.reference, *ft_input, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
}
