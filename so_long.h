/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/25 13:55:01 by faventur          #+#    #+#             */
/*   Updated: 2022/03/31 13:13:30 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <math.h>

typedef struct s_vars {
	void	*mlx;
	void	*win;
}				t_vars;

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;

typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	a;
}				t_color;

typedef struct s_coordonates {
	int	x;
	int	y;
}				t_coordonates;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color);
void	draw_circle(t_data *data, int x, int y, int r, int color);

#endif