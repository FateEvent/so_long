/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:55:07 by faventur          #+#    #+#             */
/*   Updated: 2022/04/01 18:04:48 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <stdio.h>

void	my_mlx_pixel_put(t_image *data, int x, int y, int color)
{
	char	*dst;

	dst = data->ref + (y * data->line_size + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	close(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	return (0);
}

void	ft_put_background(t_image image, t_vars vars)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i * image.size.y < 1080)
	{	
		while (j * image.size.x < 1920)
		{		
			mlx_put_image_to_window(vars.mlx, vars.win, image.ref, j * (image.size.x - 1), i * (image.size.y - 1));
			j++;
		}
		j = 0;
		i++;
	}
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.ref = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.ref, &img.bits_per_pixel, &img.line_size, &img.endian);
	return (img);
}

int	main(void)
{
	t_vars	vars;
	t_image	img;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1980, "Hello Worlds!");
	img = ft_new_sprite(vars.mlx, "./images/chessboard.xpm");
	ft_put_background(img, vars);
	mlx_key_hook(vars.win, close, &vars);
	mlx_loop(vars.mlx);
}
