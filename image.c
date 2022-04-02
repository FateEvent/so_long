/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:07:41 by faventur          #+#    #+#             */
/*   Updated: 2022/04/02 13:33:35 by faventur         ###   ########.fr       */
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

t_image	ft_put_background(t_program data, char *path)
{
	t_image	bg;
	int		i;
	int		j;

	bg.reference = mlx_xpm_file_to_image(data.mlx, path, &bg.size.x,
			&bg.size.y);
	bg.pixels = mlx_get_data_addr(bg.reference, &bg.bits_per_pixel,
			&bg.line_size, &bg.endian);
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
	return (bg);
}
