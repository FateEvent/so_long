/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:13:32 by faventur          #+#    #+#             */
/*   Updated: 2022/04/18 17:29:08 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

int	main(void)
{
	t_program	program;
	char		**arr;

	program.mlx = mlx_init();
	program.window = ft_new_window(program.mlx, 1980, 1080, "Befana!");
	ft_put_background(program, "images/chessboard.xpm");
	program.sprite = ft_new_sprite(program.mlx, "images/befana.xpm");
	arr = ft_map_reader("map.ber");
	if (arr == NULL)
		exit(0);
	if (!ft_map_parser(arr))
		exit(0);
	program.sprite_position = ft_get_coordinates(arr, 'P');
	ft_printf("vector: %d %d\n", program.sprite_position.y, program.sprite_position.y);

	mlx_put_image_to_window(program.mlx, program.window.reference,
		program.sprite.reference, program.sprite_position.x,
		program.sprite_position.y);
	mlx_key_hook(program.window.reference, *ft_input, &program);
	mlx_loop_hook(program.mlx, *ft_update, &program);
	mlx_loop(program.mlx);
}
