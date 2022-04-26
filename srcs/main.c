/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:13:32 by faventur          #+#    #+#             */
/*   Updated: 2022/04/26 20:16:50 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

int	main(void)
{
	t_program	program;
	t_vector	size;

	program.mlx = mlx_init();
	program.map = ft_map_reader("map.ber");
	if (program.map != NULL || !ft_map_parser(program.map))
	{
		size = calculate_window_size(program.map);
		program.window = ft_new_window(program.mlx, size.x, size.y, "Befana!");
		program.pixies = ft_put_sprite(program);
		ft_display_map(program, program.map, program.pixies);
		program.sprite = ft_new_sprite(program.mlx, "images/befana_right.xpm");
		program.sprite_position = ft_get_coordinates(program.map, 'P');
		mlx_put_image_to_window(program.mlx, program.window.reference,
			program.sprite.reference, program.sprite_position.x,
			program.sprite_position.y);
		mlx_key_hook(program.window.reference, *ft_input, &program);
		mlx_loop_hook(program.mlx, *ft_update, &program);
		mlx_loop(program.mlx);
		ft_map_freer(program.map);
	}
	else
		exit(0);
}
