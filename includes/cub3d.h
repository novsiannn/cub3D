/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: novsiann <novsiann@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 15:13:54 by ibellash          #+#    #+#             */
/*   Updated: 2023/11/19 13:29:09 by novsiann         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "libft/libft.h"
# include <stdio.h>
# include <limits.h>
# include <fcntl.h>
# include <math.h>
# include <time.h>
# include "../mlx/mlx.h"

# define KEYPRESS 2
# define KEYRELEASE 3
# define X_EVENT_KEY_PRESS 2
# define X_EVENT_KEY_EXIT 17

# define ESC_KEY 53
# define KEY_ARR_LEFT 123
# define KEY_ARR_RIGHT 124
# define W_KEY 13
# define S_KEY 1
# define D_KEY 2
# define A_KEY 0
# define KEY_SHIFT_LEFT	257

# define TEX_SIZE 128

# define ARGS_ERROR "Wrong amount of arguments!\n"
# define FILE_ERROR "Given file path is invalid!\n"
# define MAP_ARGS_ERROR "There is some problem with arguments in file!"
# define MAP_ARGS_COLOR_ERROR "Color variable has incorect value!"
# define MAP_WALL_ERROR "Map is not surrounded by walls!\n"
# define MAP_EMPTY_LINES_ERROR "Map has some empty lines inside!\n"
# define MAP_EMPTY_ERROR "There is seems to be no map in file!\n"
# define MAP_PATH_ERROR "Map has no valid path!\n"
# define MAP_COMPONENTS_ERROR "Map doesn't have the player starting \
position, has multiple starting positions or has some invalid characters!\n"
# define SPRITE_ERROR "Couldn't find a sprite. Does it exist?\n"

typedef struct s_image
{
	void	*xpm_ptr;
	int		x;
	int		y;
}	t_image;

typedef struct s_raycast
{
	void		*mlx;
	void		*win;
	void		*img;
	char		*img_addr;
	double		pos_x;
	double		pos_y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	int			map_x;
	int			map_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			step_x;
	int			step_y;
	int			hit;
	int			side;
	int			line_height;
	int			draw_start;
	int			draw_end;
	int			color;
	double		move_speed;
	double		rot_speed;
	double		old_dir_x;
	double		old_plane_x;
	double		frametime;
	double		time;
	double		oldtime;
	int			line_length;
	int			endian;
	int			bits_per_pixel;
	int			texnum;
	double		wallx;
	int			texx;
	int			texy;
	double		step;
	double		texpos;
	uint32_t	colr;
}	t_raycast;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_raycast	*rays;
	char		**map;
	int			**imap;
	int			screen_width;
	int			screen_height;
	int			tex_width;
	int			tex_height;
	uint32_t	**texture;
	t_image		wall_north;
	t_image		wall_south;
	t_image		wall_west;
	t_image		wall_east;
	int			floor_color;
	int			ceiling_color;
	int			size_line;
	char		player_direction;
	double		movespeed;
	double		rotspeed;
	int			key_w;
	int			key_s;
	int			key_d;
	int			key_a;
	int			key_esc;
	int			key_right;
	int			key_left;
}	t_game;

int				close_game(t_game *game);
int				init_game_vars(t_game *game);
void			throw_error(t_game *game, char *message);
char			**read_map(t_game *game, char *map);
void			init_map_data(t_game *game, char *path);
size_t			matrix_len(char **str);
void			matrix_free(char **str);
char			**matrix_dup(char **str, int size);
void			free_game(t_game *game);
void			init_map_vars(t_game *game, char **file_content);
char			**ft_split_spaces(char *s);
int				ft_isspace(int c);
t_image			read_xmp_image(void *mlx, char *file);
void			my_mlx_pixel_put(t_game *game, int x, int y, uint32_t color);
unsigned int	ft_get_ticks(void);
void			init_map(t_game *game, char **file_content);
int				check_components(t_game *game, char **map, int i);
int				check_walls(char **map);
int				check_empty(char **map);
void			map_check_errors(t_game *game, char **file_content);
int				check_if_nums(char *num);
char			**get_map(char **file_content);
void			fill_with_ones(t_game *game);
int				is_empty_line(char *line);

int				create_trgb(int t, int r, int g, int b);
int				get_t(int trgb);
int				get_r(int trgb);
int				get_g(int trgb);
int				get_b(int trgb);

int				init_textures(t_game *g);
int				draw(t_game *game);
void			calc_hit(t_game *game);
void			check_side(t_game *game);
void			calc_side_dist(t_game *game);
void			calc_side_dist_y(t_game *game);
void			init_wall_casting(t_game *game, int i); 
int				keys(int keycode, t_game *game);
int				key_hook(t_game *d);
int				key_release(int key, t_game *d);
int				key_press(int key, t_game *d);
void			key_up(t_game *game);
void			key_down(t_game *game);
void			key_a(t_game *game);
void			key_d(t_game *game);
void			rotate(int direction, t_game *d, double rotspeed);

#endif
