/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forms_and_colours.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/16 11:58:12 by faventur          #+#    #+#             */
/*   Updated: 2022/04/16 12:01:37 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORMS_AND_COLOURS_H
# define FORMS_AND_COLOURS_H

# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include "../libft/includes/libft.h"
# include "../libft/includes/ft_printf.h"
# include "../libft/includes/get_next_line.h"

// ----------------------------------
// MACROS

# ifndef ANIMATION_FRAMES
#  define ANIMATION_FRAMES 10
# endif

// ----------------------------------
// STRUCTS

typedef struct s_prop {
	int	item;
	int	exit;
	int	start_pos;
}				t_prop;

/* vector with an x and y */
typedef struct s_vector
{
	int	x;
	int	y;
}				t_vector;

/* A pointer to the window and its size */
typedef struct s_window {
	void		*reference;
	t_vector	size;
}				t_window;

/* The 4 values that define a color */
typedef struct s_color {
	int	r;
	int	g;
	int	b;
	int	a;
}	t_color;

/* all info needed for an image */
typedef struct s_image {
	void		*reference;
	t_vector	size;
	char		*pixels;
	int			bits_per_pixel;
	int			line_size;
	int			endian;
}				t_image;

typedef struct s_program {
	void		*mlx;
	t_window	window;
	t_image		sprite;
	t_vector	sprite_position;
}				t_program;

// ---------------------------------
// FUNCTIONS

t_color	hex_to_rgb_converter(int hex_value);
t_color	lerp(t_color a, t_color b, float t);
int	    rgb_to_hex_converter(t_color rgb);
int	    add_shade(double distance, int color);
int	    get_opposite(int color);

#endif