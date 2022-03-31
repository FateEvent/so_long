/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/31 12:17:59 by faventur          #+#    #+#             */
/*   Updated: 2022/03/31 13:13:03 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_circle(t_data *data, int x, int y, int r, int color)
{
	static const double	pi = 3.1415926535;
	double				i;
	double				angle;
	double				x1;
	double				y1;

	i = 0;
	while (i < 360)
	{
		angle = i;
		x1 = r * cos(angle * pi / 180);
		y1 = r * sin(angle * pi / 180);
		my_mlx_pixel_put(data, x + x1, y + y1, color);
		i += 0.1;
	}
}
