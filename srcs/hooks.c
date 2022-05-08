/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 13:52:36 by faventur          #+#    #+#             */
/*   Updated: 2022/05/08 15:18:55 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	ft_display_moves_pt2(t_program *d, t_vector pos, int key, int *counter)
{
	if (key == 1 && d->map[pos.y + 1][pos.x] != '1')
	{
		if (d->map[pos.y + 1][pos.x] == 'C' || d->map[pos.y + 1][pos.x] == '0')
		{
			d->map[pos.y][pos.x] = '0';
			d->map[pos.y + 1][pos.x] = 'F';
			(*counter)++;
		}
		else if (d->map[pos.y + 1][pos.x] == 'E' && verify_conditions(d->map))
			exit(0);
	}
	else if (key == 13 && d->map[pos.y - 1][pos.x] != '1')
	{
		if (d->map[pos.y - 1][pos.x] == 'C' || d->map[pos.y - 1][pos.x] == '0')
		{
			d->map[pos.y][pos.x] = '0';
			d->map[pos.y - 1][pos.x] = 'B';
			(*counter)++;
		}
		else if (d->map[pos.y - 1][pos.x] == 'E' && verify_conditions(d->map))
			exit(0);
	}
	else if (key == 53)
		exit(0);
}

void	ft_display_moves(t_program *d, int key, t_vector pos, int *counter)
{
	if (key == 0 && d->map[pos.y][pos.x - 1] != '1')
	{
		if (d->map[pos.y][pos.x - 1] == 'C' || d->map[pos.y][pos.x - 1] == '0')
		{
			d->map[pos.y][pos.x] = '0';
			d->map[pos.y][pos.x - 1] = 'L';
			(*counter)++;
		}
		else if (d->map[pos.y][pos.x - 1] == 'E' && verify_conditions(d->map))
			exit(0);
	}
	else if (key == 2 && d->map[pos.y][pos.x + 1] != '1')
	{
		if (d->map[pos.y][pos.x + 1] == 'C' || d->map[pos.y][pos.x + 1] == '0')
		{
			d->map[pos.y][pos.x] = '0';
			d->map[pos.y][pos.x + 1] = 'P';
			(*counter)++;
		}
		else if (d->map[pos.y][pos.x + 1] == 'E' && verify_conditions(d->map))
			exit(0);
	}
	else
		ft_display_moves_pt2(d, pos, key, counter);
}

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
