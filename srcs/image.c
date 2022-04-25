/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:07:41 by faventur          #+#    #+#             */
/*   Updated: 2022/04/25 17:30:28 by faventur         ###   ########.fr       */
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

void	ft_invoke_pixie(char c, int *i, t_program data, t_image *pixie)
{
	if (c == '1')
		mlx_put_image_to_window(data.mlx, data.window.reference,
			pixie[0].reference, i[1] * (pixie[0].size.x - 1),
			i[0] * (pixie[0].size.y - 1));
	else if (c == 'C')
		mlx_put_image_to_window(data.mlx, data.window.reference,
			pixie[1].reference, i[1] * (pixie[1].size.x - 1),
			i[0] * (pixie[1].size.y - 1));
	else if (c == 'E')
		mlx_put_image_to_window(data.mlx, data.window.reference,
			pixie[2].reference, i[1] * (pixie[2].size.x - 1),
			i[0] * (pixie[2].size.y - 1));
	else if (c == 'P')
		mlx_put_image_to_window(data.mlx, data.window.reference,
			pixie[3].reference, i[1] * (pixie[3].size.x - 1),
			i[0] * (pixie[3].size.y - 1));
	else
		mlx_put_image_to_window(data.mlx, data.window.reference,
			pixie[4].reference, i[1] * (pixie[4].size.x - 1),
			i[0] * (pixie[4].size.y - 1));
}

t_image	*ft_put_sprite(t_program data)
{
	t_image	*pixie;

	pixie = malloc(sizeof(t_image) * 6);
	pixie[0].reference = mlx_xpm_file_to_image(data.mlx, "images/wall.xpm",
			&pixie[0].size.x, &pixie[0].size.y);
	pixie[1].reference = mlx_xpm_file_to_image(data.mlx, "images/sugarcane.xpm",
			&pixie[1].size.x, &pixie[1].size.y);
	pixie[2].reference = mlx_xpm_file_to_image(data.mlx, "images/house.xpm",
			&pixie[2].size.x, &pixie[2].size.y);
	pixie[3].reference = mlx_xpm_file_to_image(data.mlx,
			"images/befana_right.xpm", &pixie[3].size.x, &pixie[3].size.y);
	pixie[4].reference = mlx_xpm_file_to_image(data.mlx,
			"images/grass_tile.xpm", &pixie[4].size.x, &pixie[4].size.y);
	return (pixie);
}

void	ft_display_map(t_program data, char **map, t_image *pixie)
{
	int		i[2];
	char	c;

	i[0] = 0;
	i[1] = 0;
	while (i[0] * pixie[0].size.y < data.window.size.y && map[i[0]])
	{	
		while (i[1] * pixie[0].size.x < data.window.size.x
			&& map[i[0]][i[1]] != '\n')
		{
			c = map[i[0]][i[1]];
			ft_invoke_pixie(c, i, data, pixie);
			i[1]++;
		}
		i[1] = 0;
		i[0]++;
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
