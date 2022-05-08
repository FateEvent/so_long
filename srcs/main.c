/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:13:32 by faventur          #+#    #+#             */
/*   Updated: 2022/05/08 15:25:07 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

int	main(void)
{
	t_program	program;
	t_vector	size;
	int			i;

	i = 0;
	program.mlx = mlx_init();
	program.map = ft_map_reader("map02.ber");
	if (program.map != NULL || !ft_map_parser(program.map))
	{
		program.frame = 0;
		program.step_counter = 0;
		size = calculate_window_size(program.map);
		program.window = ft_new_window(program.mlx, size.x, size.y,
				"Befana!");
		ft_printf("ora?");
		program.pixies = ft_put_sprite(&program);
		ft_display_map(&program, program.map, program.pixies);
		mlx_hook(program.window.reference, 2, 1L << 0, *ft_input, &program);
		mlx_loop_hook(program.mlx, *ft_update, &program);
		mlx_loop(program.mlx);
	}
	else
		exit(0);
}
