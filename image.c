/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:07:41 by faventur          #+#    #+#             */
/*   Updated: 2022/04/03 12:14:19 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_new_image() function returns an image of <width> per <height> black
** pixels.
**
** The ft_new_sprite() function returns an image with the sprite found in
** the <path> string.
*/

#include "so_long.h"

void	ft_put_sprite(t_program data, char **map)
{
	t_image	pixie[6];
	int		i;
	int		j;

	pixie[0].reference = mlx_xpm_file_to_image(data.mlx, "player.xpm",
			&pixie[0].size.x, &pixie[0].size.y);
	pixie[1].reference = mlx_xpm_file_to_image(data.mlx, "player.xpm",
			&pixie[1].size.x, &pixie[1].size.y);
	pixie[2].reference = mlx_xpm_file_to_image(data.mlx, "player.xpm",
			&pixie[2].size.x, &pixie[2].size.y);
	pixie[3].reference = mlx_xpm_file_to_image(data.mlx, "player.xpm",
			&pixie[3].size.x, &pixie[3].size.y);
	i = 0;
	j = 0;
	while (map[i] != NULL)
	{	
		while (map[i][j] != NULL)
		{
			if (map[i][j] == '1')
				mlx_put_image_to_window(data.mlx, data.window.reference,
					pixie[0].reference, j * (pixie[0].size.x - 1),
					i * (pixie[0].size.y - 1));
			else if (map[i][j] == 'C')
				mlx_put_image_to_window(data.mlx, data.window.reference,
					pixie[1].reference, j * (pixie[1].size.x - 1),
					i * (pixie[1].size.y - 1));
			else if (map[i][j] == 'E')
				mlx_put_image_to_window(data.mlx, data.window.reference,
					pixie[2].reference, j * (pixie[2].size.x - 1),
					i * (pixie[2].size.y - 1));
			else if (map[i][j] == 'P')
				mlx_put_image_to_window(data.mlx, data.window.reference,
					pixie[3].reference, j * (pixie[3].size.x - 1),
					i * (pixie[3].size.y - 1));
			j++;
		}
		j = 0;
		i++;
	}
}

void	ft_put_background(t_program data, char *path)
{
	t_image	bg;
	int		i;
	int		j;

	bg.reference = mlx_xpm_file_to_image(data.mlx, path, &bg.size.x,
			&bg.size.y);
	i = 0;
	j = 0;
	while (i * bg.size.y < data.window.size.y)
	{	
		while (j * bg.size.x < data.window.size.x)
		{		
			mlx_put_image_to_window(data.mlx, data.window.reference,
				bg.reference, j * (bg.size.x - 1),
				i * (bg.size.y - 1));
			j++;
		}
		j = 0;
		i++;
	}
}

t_image	ft_new_image(void *mlx, int width, int height)
{
	t_image	img;

	img.reference = mlx_new_image(mlx, width, height);
	img.size.x = width;
	img.size.x = height;
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}

t_image	ft_new_sprite(void *mlx, char *path)
{
	t_image	img;

	img.reference = mlx_xpm_file_to_image(mlx, path, &img.size.x, &img.size.y);
	img.pixels = mlx_get_data_addr(img.reference, &img.bits_per_pixel,
			&img.line_size, &img.endian);
	return (img);
}
