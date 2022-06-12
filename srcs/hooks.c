/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:52:36 by faventur          #+#    #+#             */
/*   Updated: 2022/06/12 18:12:59 by faventur         ###   ########.fr       */
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
	return (0);
}

static void	ft_detail_cond(t_program *program, t_update vars)
{
	if (program->map[vars.villain_pos.y - 1][vars.villain_pos.x] == '1'
		&& program->map[vars.villain_pos.y - 1][vars.villain_pos.x + 1] == '1')
	{
		program->map[vars.villain_pos.y][vars.villain_pos.x] = '0';
		program->map[vars.villain_pos.y][vars.villain_pos.x + 1] = 'K';
	}
	if (program->map[vars.villain_pos.y][vars.villain_pos.x + 1] == '1'
		&& program->map[vars.villain_pos.y + 1][vars.villain_pos.x + 1] == '1')
	{
		program->map[vars.villain_pos.y][vars.villain_pos.x] = '0';
		program->map[vars.villain_pos.y + 1][vars.villain_pos.x] = 'K';
	}
	if (program->map[vars.villain_pos.y + 1][vars.villain_pos.x] == '1'
		&& program->map[vars.villain_pos.y + 1][vars.villain_pos.x - 1] == '1')
	{
		program->map[vars.villain_pos.y][vars.villain_pos.x] = '0';
		program->map[vars.villain_pos.y][vars.villain_pos.x - 1] = 'K';
	}
	if (program->map[vars.villain_pos.y][vars.villain_pos.x - 1] == '1'
		&& program->map[vars.villain_pos.y - 1][vars.villain_pos.x - 1] == '1')
	{
		program->map[vars.villain_pos.y][vars.villain_pos.x] = '0';
		program->map[vars.villain_pos.y - 1][vars.villain_pos.x] = 'K';
	}
}

int	ft_update(void *param)
{
	t_program	*program;
	t_update	vars;
	char		*number;

	program = (t_program *)param;
	vars.basic_pos = ft_get_char_pos((*program).map);
	vars.villain_pos = ft_get_x_and_y((*program).map, 'K');
	vars.b_var = sin(program->frame / 20) * 2;
	vars.v_var = sin(program->frame / 20) * 2;
	program->frame++;
	if (program->frame % 100 == 0)
		ft_detail_cond(program, vars);
	mlx_clear_window(program->mlx, program->window.reference);
	ft_display_map(program, (*program).map, (*program).pixies);
	ft_invoke_char(program, program->pixies, vars.basic_pos, vars.b_var);
	ft_invoke_enemy(program, program->pixies, vars.villain_pos, vars.v_var);
	number = ft_itoa((*program).step_counter);
	mlx_string_put((*program).mlx, (*program).window.reference, 10, 44,
		0xffffffff, number);
	return (0);
}
