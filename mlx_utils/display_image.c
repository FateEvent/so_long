/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_image.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:07:41 by faventur          #+#    #+#             */
/*   Updated: 2022/04/19 15:26:12 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** The ft_put_background() function creates a background by the repetition
** of an image. The amount of times the image is repeated is function of
** the size of the window.
*/

#include "mlx_utils.h"

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
