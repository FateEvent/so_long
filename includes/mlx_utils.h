/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: faventur <faventur@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/02 12:06:01 by faventur          #+#    #+#             */
/*   Updated: 2022/06/12 18:07:39 by faventur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_UTILS_H
# define MLX_UTILS_H

# include <mlx.h>
# include <fcntl.h>
# include <sys/types.h>
# include <math.h>
# include "libft.h"
# include "ft_printf.h"
# include "get_next_line.h"

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
	t_image		*pixies;
	char		**map;
	int			frame;
	int			step_counter;
}				t_program;

typedef struct s_nme
{
	t_vector	pos;
	t_vector	prev;
}				t_nme;

typedef struct s_update
{
	t_vector	basic_pos;
	t_vector	villain_pos;
	int			b_var;
	int			v_var;
}				t_update;

// ---------------------------------
// FUNCTIONS

t_window	ft_new_window(void *mlx, int width, int height, char *name);
t_vector	calculate_window_size(char **map);

t_image		ft_new_sprite(void *mlx, char *path);
t_vector	ft_get_coordinates(char **map, char prop);
t_vector	ft_get_x_and_y(char **map, char prop);
t_vector	ft_get_char_pos(char **map);
char		who_is_it(char **map);
void		ft_put_background(t_program *data, char *path);
t_image		*ft_put_sprite(t_program *data);
void		ft_invoke_pixie(char c, int *i, t_program *data, t_image *pixie);
void		ft_invoke_char(t_program *data, t_image *pixie, t_vector pos,
				int var);
void		ft_invoke_enemy(t_program *data, t_image *pixie, t_vector pos,
				int var);
void		ft_display_map(t_program *data, char **map, t_image *pixie);

void		ft_display_moves(t_program *d, int key, t_vector pos, int *counter);
void		move_ur_ass(t_program *data);
void		track_ur_move_left(t_program *data, t_nme death);
void		track_ur_move_up(t_program *data, t_nme death);
void		track_ur_move_right(t_program *data, t_nme death);
void		track_ur_move_down(t_program *data, t_nme death);
int			ft_swing(t_program *data);

int			ft_map_parser(char **map);
char		**ft_map_reader(char *filename);

int			ft_input(int key, void *param);
int			ft_update(void *param);

void		ft_prop_init(t_prop *obj);
int			verify_conditions(char **map);

void		check_args(char argc);
void		check_map_extension(char *argv[]);

void		ft_break_the_game(t_program *data, char *end_msg);
int			ft_close(void);

#endif