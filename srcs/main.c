/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:13:32 by faventur          #+#    #+#             */
/*   Updated: 2022/04/19 15:19:13 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

int	main(void)
{
	t_program	program;
	t_image		*pix;
	char		**arr;

	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 660, 500, "Befana!");
	arr = ft_map_reader("map.ber");
	if (arr != NULL || !ft_map_parser(arr))
	{
		pix = ft_put_sprite(program);
		ft_display_map(program, arr, pix);
		program.sprite = ft_new_sprite(program.mlx, "images/befana_right.xpm");
		program.sprite_position = ft_get_coordinates(arr, 'P');
		mlx_put_image_to_window(program.mlx, program.window.reference,
			program.sprite.reference, program.sprite_position.x,
			program.sprite_position.y);
		mlx_key_hook(program.window.reference, *ft_input, &program);
		mlx_loop_hook(program.mlx, *ft_update, &program);
		mlx_loop(program.mlx);
	}
	else
		exit(0);
}
