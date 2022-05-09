/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:52:36 by faventur          #+#    #+#             */
/*   Updated: 2022/05/09 18:21:02 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

int	ft_input(int key, void *param)
{
	t_program	*program;
	t_vector	pos;
	char		*number;

	program = (t_program *)param;
	pos = ft_get_char_pos((*program).map);
	ft_display_moves(program, key, pos, &(*program).step_counter);
	move_ur_ass(program);
	mlx_clear_window(program->mlx, program->window.reference);
	ft_display_map(program, (*program).map, (*program).pixies);
	number = ft_itoa((*program).step_counter);
	mlx_string_put((*program).mlx, (*program).window.reference, 10, 44,
		0xffffffff, number);
	ft_printf("Number of steps: %d\n", (*program).step_counter);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program;
	t_vector	basic_pos;
	int			var;

	program = (t_program *)param;
	basic_pos = ft_get_char_pos((*program).map);
	var = sin(program->frame / 20) * 2;
	program->frame++;
	ft_invoke_char(program, (*program).pixies, basic_pos, var);
	return (0);
}

int	ft_swing(t_program *data)
{
	t_vector	basic_pos;
	int			var;

	basic_pos = ft_get_x_and_y(data->map, 'K');
	var = sin(data->frame / 13) * 2;
	data->frame++;
	ft_invoke_enemy(data, data->pixies, basic_pos, var);
	return (0);
}
