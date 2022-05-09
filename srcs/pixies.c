/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pixies.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 18:19:27 by faventur          #+#    #+#             */
/*   Updated: 2022/05/09 18:19:46 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx_utils.h"

void	ft_invoke_enemy(t_program *data, t_image *pixie, t_vector pos, int var)
{
	mlx_put_image_to_window(data->mlx, data->window.reference,
		pixie[3].reference, pos.x * (pixie[3].size.x - 1),
		pos.y * (pixie[3].size.y - 1));
	mlx_put_image_to_window(data->mlx, data->window.reference,
		pixie[8].reference, pos.x * (pixie[8].size.x - 1),
		pos.y * (pixie[8].size.y - var));
}

void	ft_invoke_char(t_program *data, t_image *pixie, t_vector pos, int var)
{
	mlx_put_image_to_window(data->mlx, data->window.reference,
		pixie[3].reference, pos.x * (pixie[3].size.x - 1),
		pos.y * (pixie[3].size.y - 1));
	if (data->map[pos.y][pos.x] == 'P')
		mlx_put_image_to_window(data->mlx, data->window.reference,
			pixie[4].reference, pos.x * (pixie[4].size.x - 1),
			pos.y * (pixie[4].size.y - var));
	else if (data->map[pos.y][pos.x] == 'F')
		mlx_put_image_to_window(data->mlx, data->window.reference,
			pixie[5].reference, pos.x * (pixie[5].size.x - 1),
			pos.y * (pixie[5].size.y - var));
	else if (data->map[pos.y][pos.x] == 'B')
		mlx_put_image_to_window(data->mlx, data->window.reference,
			pixie[6].reference, pos.x * (pixie[6].size.x - 1),
			pos.y * (pixie[6].size.y - var));
	else if (data->map[pos.y][pos.x] == 'L')
		mlx_put_image_to_window(data->mlx, data->window.reference,
			pixie[7].reference, pos.x * (pixie[7].size.x - 1),
			pos.y * (pixie[7].size.y - var));
}

static void	ft_invoke_pixie_pt2(char c, int *i, t_program *data, t_image *pixie)
{
	if (c == 'K')
		ft_swing(data);
	else
		mlx_put_image_to_window(data->mlx, data->window.reference,
			pixie[3].reference, i[1] * (pixie[3].size.x - 1),
			i[0] * (pixie[3].size.y - 1));
}

void	ft_invoke_pixie(char c, int *i, t_program *data, t_image *pixie)
{
	if (c == '1')
		mlx_put_image_to_window(data->mlx, data->window.reference,
			pixie[0].reference, i[1] * (pixie[0].size.x - 1),
			i[0] * (pixie[0].size.y - 1));
	else if (c == 'C')
	{
		mlx_put_image_to_window(data->mlx, data->window.reference,
			pixie[3].reference, i[1] * (pixie[3].size.x - 1),
			i[0] * (pixie[3].size.y - 1));
		mlx_put_image_to_window(data->mlx, data->window.reference,
			pixie[1].reference, i[1] * (pixie[1].size.x - 1),
			i[0] * (pixie[1].size.y - 1));
	}
	else if (c == 'E')
	{
		mlx_put_image_to_window(data->mlx, data->window.reference,
			pixie[3].reference, i[1] * (pixie[3].size.x - 1),
			i[0] * (pixie[3].size.y - 1));
		mlx_put_image_to_window(data->mlx, data->window.reference,
			pixie[2].reference, i[1] * (pixie[2].size.x - 1),
			i[0] * (pixie[2].size.y - 1));
	}
	else
		ft_invoke_pixie_pt2(c, i, data, pixie);
}

t_image	*ft_put_sprite(t_program *data)
{
	t_image	*pixie;

	pixie = malloc(sizeof(t_image) * 9);
	pixie[0].reference = mlx_xpm_file_to_image(data->mlx,
			"images/wall.xpm", &pixie[0].size.x, &pixie[0].size.y);
	pixie[1].reference = mlx_xpm_file_to_image(data->mlx,
			"images/sugarcane.xpm", &pixie[1].size.x, &pixie[1].size.y);
	pixie[2].reference = mlx_xpm_file_to_image(data->mlx,
			"images/house.xpm", &pixie[2].size.x, &pixie[2].size.y);
	pixie[3].reference = mlx_xpm_file_to_image(data->mlx,
			"images/grass_tile.xpm", &pixie[3].size.x, &pixie[3].size.y);
	pixie[4].reference = mlx_xpm_file_to_image(data->mlx,
			"images/befana_right.xpm", &pixie[4].size.x, &pixie[4].size.y);
	pixie[5].reference = mlx_xpm_file_to_image(data->mlx,
			"images/befana_front.xpm", &pixie[5].size.x, &pixie[5].size.y);
	pixie[6].reference = mlx_xpm_file_to_image(data->mlx,
			"images/befana_back.xpm", &pixie[6].size.x, &pixie[6].size.y);
	pixie[7].reference = mlx_xpm_file_to_image(data->mlx,
			"images/befana_left.xpm", &pixie[7].size.x, &pixie[7].size.y);
	pixie[8].reference = mlx_xpm_file_to_image(data->mlx,
			"images/death.xpm", &pixie[8].size.x, &pixie[8].size.y);
	return (pixie);
}
