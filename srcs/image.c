/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:07:41 by faventur          #+#    #+#             */
/*   Updated: 2022/04/18 17:30:10 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_new_image() function returns an image of <width> per <height> black
** pixels.
**
** The ft_new_sprite() function returns an image with the sprite found in
** the <path> string.
*/

#include "mlx_utils.h"

void	ft_invoke_pixie(t_program data, char **map, t_image *pixie, int *i)
{
	if (map[i[0]][i[1]] == '1')
		mlx_put_image_to_window(data.mlx, data.window.reference,
			pixie[0].reference, i[1] * (pixie[0].size.x - 1),
			i[0] * (pixie[0].size.y - 1));
	else if (map[i[0]][i[1]] == 'C')
		mlx_put_image_to_window(data.mlx, data.window.reference,
			pixie[1].reference, i[1] * (pixie[1].size.x - 1),
			i[0] * (pixie[1].size.y - 1));
	else if (map[i[0]][i[1]] == 'E')
		mlx_put_image_to_window(data.mlx, data.window.reference,
			pixie[2].reference, i[1] * (pixie[2].size.x - 1),
			i[0] * (pixie[2].size.y - 1));
	else if (map[i[0]][i[1]] == 'P')
		mlx_put_image_to_window(data.mlx, data.window.reference,
			pixie[3].reference, i[1] * (pixie[3].size.x - 1),
			i[0] * (pixie[3].size.y - 1));
}

void	ft_put_sprite(t_program data, char **map)
{
	t_image	pixie[6];
	int		index[2];

	pixie[0].reference = mlx_xpm_file_to_image(data.mlx, "images/wall.xpm",
			&pixie[0].size.x, &pixie[0].size.y);
	pixie[1].reference = mlx_xpm_file_to_image(data.mlx, "images/sweet.xpm",
			&pixie[1].size.x, &pixie[1].size.y);
	pixie[2].reference = mlx_xpm_file_to_image(data.mlx, "images/house.xpm",
			&pixie[2].size.x, &pixie[2].size.y);
	pixie[3].reference = mlx_xpm_file_to_image(data.mlx, "images/befana.xpm",
			&pixie[3].size.x, &pixie[3].size.y);
	pixie[4].reference = mlx_xpm_file_to_image(data.mlx, "player.xpm",
			&pixie[3].size.x, &pixie[3].size.y);
	index[0] = 0;
	index[1] = 0;
	while (map[index[0]])
	{	
		while (map[index[0]][index[1]])
		{
			ft_invoke_pixie(data, map, pixie, index);
			index[1]++;
		}
		index[1] = 0;
		index[0]++;
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
