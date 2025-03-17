/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bouhammo <bouhammo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/09 01:22:14 by bouhammo          #+#    #+#             */
/*   Updated: 2025/03/17 16:57:58 by bouhammo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB_H
# define CUB_H
# include "./MLX42/include/MLX42/MLX42.h"
# include "./get_next_line_1/get_next_line.h"
# include "./libft_1/libft.h"
# include <fcntl.h>
# include <limits.h>
# include <math.h>
# include <stdio.h>

# define WINDOW_WIDTH 1200
# define WINDOW_HEIGHT 800
# define TILE_SIZE 32
# define FOV_ANGLE 1.0471975512
# define PLAYER_SPEED 9
# define ROTATION_SPEED 0.045

typedef struct s_joined
{
	int					i;
	int					count;
	char				*str;
}						t_joined;
typedef struct s_west_pxl
{
	int					**west_pxl;
	int					width;
	int					height;
}						t_west_pxl;

typedef struct s_info_texture
{
	int					y;
	double				top_const;
	double				buttom_const;
	double				get_buttom;
	double				line;
	uint32_t			texture_x;
}						t_info_texture;
typedef struct s_north_pxl
{
	int					**north_pxl;
	int					width;
	int					height;
}						t_north_pxl;
typedef struct s_east_pxl
{
	int					**east_pxl;
	int					width;
	int					height;
}						t_east_pxl;
typedef struct s_south_pxl
{
	int					**south_pxl;
	int					width;
	int					height;
}						t_south_pxl;

typedef struct s_image_to_pxl
{
	t_west_pxl			west_pxl;
	t_north_pxl			north_pxl;
	t_east_pxl			east_pxl;
	t_south_pxl			south_pxl;
}						t_image_to_pxl;

typedef struct s_elements
{
	char				**element;
	int					floor[3];
	int					ceiling[3];
	mlx_texture_t		*north_t;
	mlx_image_t			*north_g;
	mlx_texture_t		*east_t;
	mlx_image_t			*east_g;
	mlx_texture_t		*south_t;
	mlx_image_t			*south_g;
	mlx_texture_t		*west_t;
	mlx_image_t			*west_g;
	t_image_to_pxl		pxl_image;
}						t_elements;

typedef struct s_move
{
	double				coor_x;
	double				coor_y;
	double				width_x;
	double				height_y;

	double				turn_direction;
	double				walk_direction;
	double				rotation_angle;
	double				rotation_speed;
	double				move_speed;
}						t_move_player;

typedef struct s_draw_line
{
	double				angle;
	double				new_point_x;
	double				new_point_y;

}						t_draw_line;

typedef struct s_rays
{
	double				ray_angle;
	double				last_ray_angle;
	double				distance;
	double				x_inter_vertical;
	double				y_inter_vartical;
	double				x_inter_horizontal;
	double				y_inter_horizontal;
	int					ray_flag;
}						t_rays;

typedef struct s_position_intersec
{
	double				x;
	double				y;
	double				distance;
	double				retur;
}						t_position_intersec;

typedef struct s_build_walls
{
	double				pos_x;
	double				pos_y;
	double				distance;
	char				direction;
	char				w_e_n_s;
	double				ray_angle;
}						t_build_walls;

typedef struct s_start
{
	mlx_t				*mlx;
	t_elements			config;
	char				**content;
	char				**map;
	char				**cpy_map;
	int					x;
	int					y;
	int					len_x;
	int					len_y;
	int					p_x;
	int					p_y;

	int					offset;
	int					len_map;
	char				player;
	bool				flag_up;
	bool				flag_down;
	mlx_image_t			*img;
	t_move_player		*move;
	t_draw_line			*draw;
	t_rays				*ray;
	t_build_walls		*wall;
	t_position_intersec	*inter;
}						t_start;

typedef struct s_intersection
{
	double				x_inter;
	double				y_inter;
	double				x_step;
	double				y_step;
	double				a;
}						t_intersection;

typedef struct draw_rays
{
	int					dx;
	int					dy;
	int					sx;
	int					sy;
	int					err;
	int					e2;
}						t_draw_rays;

typedef struct s_data
{
	char				*sub;
	char				*set;
	char				*trim;
}						t_data;

typedef struct s_data_2
{
	char				**split_sub;
	int					i;
	int					j;
	int					k;
	char				*native;
}						t_data_2;

typedef struct s_game
{
	char				**maap;
	int					p_x;
	int					p_y;
	int					w_map;
	int					h_map;
}						t_game;

typedef struct t_var
{
	int					i;
	int					j;
	int					count;
}						t_var;
char					*get_next_line(int fd);

void					ft_validate(char *av, t_start *var);
void					fill(t_start *var);
void					ft_check_pos(t_start *var);
void					ft_check_empty(t_start *var);
void					ft_check_around(t_start *var, int i, int j);
void					ft_check_least(char **map, char c, int *count);
void					validate_start_position(t_start *var, char **map);
int						ft_check_wall(char **map, t_start *var);
void					count_len_map(t_start *var);
char					**ft_duplicate_map(char **map, int i);
void					verify_input(t_start *var);
void					fill_map(t_start *var);
void					fill_config(t_start *var);
void					ft_config_rgb(t_start *var, t_data *to, int *count);
void					ft_set_rgb(t_start *var, t_data *to, char c);
int						ft_set_element(t_start *var);

// game
void					ft_start_game(t_start *var);

// errors
void					ft_put_error(char *s, t_start *var, t_data *to);
void					ft_just_print_error(char *s);
void					ft_ini_val(int *k, int *i);
// utils
int						ft_search(char *s, char *d);

// free
void					free_double(char **array);
void					free_trim(t_data *to);
void					free_start(t_start *var);
void					ft_free_when_exit(char *s, t_start *var, t_data *to,
							t_data_2 *d);

void					ft_to_img(t_start *var);

uint32_t				ft_put_texture(t_start *var, int ray,
							t_info_texture info);
uint32_t				ft_get_texture_y(int y, double top_const,
							double buttom_const, int texture_height);
void					ft_image_to_pxl(int ***table, uint8_t *pixels,
							unsigned int height, unsigned int width);
void					ft_convert_image(t_start *var);
int						get_rgba(int r, int g, int b, int a);
uint32_t				ft_calc_pos_pxl(t_start *var, int ray);
void					ft_initialize(t_start *var);

//////////////////////////      RayCaster
void					draw_floor_ceiling(t_start *var);
int						get_bottom_p(t_start *var, int line);
int						get_top_p(t_start *var, int line);
void					ft_check_direction(t_start *var, int ray);
void					build_walls(t_start *var, int ray);

void					print_in_wall(t_start *var, int x_map, int y_map);
void					print_in_space(t_start *var, int x_map, int y_map);
void					print_pixel(t_start *var);
void					print_pixel_player(t_start *var);

double					normalize_angle(double angle);
double					deg_to_rad(double deg);
double					rad_to_deg(double red);
void					ft_error(char *str);
int						ft_caracter(char c);

bool					is_looking_down(double angle);
bool					is_looking_up(double angle);
bool					is_looking_right(double angle);
bool					is_looking_left(double angle);

int						check_direction_horizontal(double ray_angle);
int						check_direction_vertical(double ray_angle);
int						is_wall(t_start *var, double x, double y);
int						check_len_map_valid(t_start *var, double x_inter,
							double y_inter);
void					check_distance(t_start *var, double len_a, double len_b,
							int ray);

void					get_horizontal_intersection(t_intersection *horiz,
							t_start *var, double ray_angle);
void					find_horizontal_intersection(t_start *var,
							double ray_angle);
void					get_vertical_intersection(t_intersection *vert,
							t_start *var, double ray_angle);
void					find_vertical_intersection(t_start *var,
							double ray_angle);
void					ft_intersection(t_start *var);

void					ft_put_pixel_color(t_start *var, double x, double y,
							int color);
int						check_is_wall(t_start *var, double x, double y);
void					check_move_player(t_start *var, double rotated_x,
							double rotated_y);
void					move_player(t_start *var);
void					change_deriction(t_start *var);

void					key_press(void *param);
void					initialize_angle(t_start *var);
void					initialize_move_player(t_start *var);
void					ft_game_free(t_start *var);
void					ft_start_game(t_start *var);

#endif
