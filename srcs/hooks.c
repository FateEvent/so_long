/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:52:36 by faventur          #+#    #+#             */
/*   Updated: 2022/05/01 13:01:36 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	ft_display_moves_pt2(t_program d, t_vector pos, int key)
{
	if (key == 1 && d.map[pos.y + 1][pos.x] != '1')
	{
		if (d.map[pos.y + 1][pos.x] == 'C' || d.map[pos.y + 1][pos.x] == '0')
		{
			d.map[pos.y][pos.x] = '0';
			d.map[pos.y + 1][pos.x] = 'F';
		}
		else if (d.map[pos.y + 1][pos.x] == 'E' && verify_conditions(d.map))
		{
			ft_printf("%d\n", verify_conditions(d.map));
			mlx_string_put(d.mlx, d.window.reference, 4 * 63, 13 * 63, 0xff000000, "Victory!");
		}
	}
	else if (key == 13 && d.map[pos.y - 1][pos.x] != '1')
	{
		if (d.map[pos.y - 1][pos.x] == 'C' || d.map[pos.y - 1][pos.x] == '0')
		{
			d.map[pos.y][pos.x] = '0';
			d.map[pos.y - 1][pos.x] = 'B';
		}
		else if (d.map[pos.y - 1][pos.x] == 'E' && verify_conditions(d.map))
		{
			ft_printf("%d\n", verify_conditions(d.map));
			mlx_string_put(d.mlx, d.window.reference, 4 * 63, 13 * 63, 0xff000000, "Victory!");
		}
	}
	else if (key == 53)
		exit(0);
}

void	ft_display_moves(t_program d, int key)
{
	t_vector	pos;

	pos = ft_get_char_pos(d.map);
	if (key == 0 && d.map[pos.y][pos.x - 1] != '1')
	{
		if (d.map[pos.y][pos.x - 1] == 'C' || d.map[pos.y][pos.x - 1] == '0')
		{
			d.map[pos.y][pos.x] = '0';
			d.map[pos.y][pos.x - 1] = 'L';
		}
		else if (d.map[pos.y][pos.x - 1] == 'E' && verify_conditions(d.map))
		{
			ft_printf("%d\n", verify_conditions(d.map));
			mlx_string_put(d.mlx, d.window.reference, 4 * 63, 13 * 63, 0xff000000, "Victory!");
		}
	}
	else if (key == 2 && d.map[pos.y][pos.x + 1] != '1')
	{
		if (d.map[pos.y][pos.x + 1] == 'C' || d.map[pos.y][pos.x + 1] == '0')
		{
			d.map[pos.y][pos.x] = '0';
			d.map[pos.y][pos.x + 1] = 'P';
		}
		else if (d.map[pos.y][pos.x + 1] == 'E' && verify_conditions(d.map))
		{
			ft_printf("%d\n", verify_conditions(d.map));
			mlx_string_put(d.mlx, d.window.reference, 4 * 63, 13 * 63, 0xff000000, "Victory!");
		}
	}
	else
		ft_display_moves_pt2(d, pos, key);
}

int	ft_input(int key, void *param)
{
	t_program	*program;

	program = (t_program *)param;
	ft_display_moves(*program, key);
	move_ur_ass(*program);
	mlx_clear_window(program->mlx, program->window.reference);
	ft_display_map(*program, (*program).map, (*program).pixies);
	return (0);
}

int	ft_update(void *param)
{
	t_program	*program;
	t_vector	basic_pos[2];
	t_vector	var;

	program = (t_program *)param;
	basic_pos[0] = ft_get_char_pos((*program).map);
	basic_pos[1] = ft_get_x_and_y((*program).map, 'K');
	var.x = sin(program->frame / 20) * 2;
	var.y = sin(program->frame / 13) * 2;
	program->frame++;
	ft_invoke_char(*program, (*program).pixies, basic_pos[0], var.x);
	ft_invoke_enemy(*program, (*program).pixies, basic_pos[1], var.y);
	return (0);
}
