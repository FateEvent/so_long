/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:55:01 by faventur          #+#    #+#             */
/*   Updated: 2022/04/01 16:42:40 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>

typedef struct s_vector {
	int	x;
	int	y;
}	t_vector;

typedef struct s_vars {
	void	*mlx;
	void	*win;
}	t_vars;

typedef struct s_image {
	void		*ref;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}	t_image;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

void	my_mlx_pixel_put(t_image *data, int x, int y, int color);
void	draw_circle(t_image *data, int x, int y, int r, int color);

#endif