/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yslati <yslati@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/08 16:23:11 by aaqlzim           #+#    #+#             */
/*   Updated: 2020/02/24 20:27:45 by yslati           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <math.h>
# include "../libft/libft.h"
# include "mlx.h"

# define BUFFER_SIZE 1
# define KEY_PRESS_MASK 1
# define KEY_RELEASE_MASK 2
# define KEY_PRESS 2
# define KEY_RELEASE 3
# define KEY_W 13
# define KEY_A 0
# define KEY_S 1
# define KEY_D 2
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_ESC 53
# define MOVE_SPEED 0.08
# define ROT_SPEED 0.03

typedef	struct		s_save
{
	unsigned char	*bmp;
	size_t			index;
	size_t			size;
}					t_save;

typedef struct		s_cub3d
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img;
	void			*texture_north;
	void			*texture_south;
	void			*texture_west;
	void			*texture_east;
	void			*texture_sprite;
	int				resolution_x;
	int				resolution_y;
	int				flag_north;
	int				flag_south;
	int				flag_west;
	int				flag_east;
	int				flag_sprite;
	int				flag_floor;
	int				flag_ceiling;
	int				flag_resolution;
	int				size_map_x;
	int				size_map_y;
	int				floor_r;
	int				floor_g;
	int				floor_b;
	int				ceiling_r;
	int				ceiling_g;
	int				ceiling_b;
	int				i;
	int				j;
	int				k;
	double			sprite_x[100];
	double			sprite_y[100];
	int				num_sprite;
	int				save;
	int				*data;
	int				per_pixel;
	int				size_line;
	int				endian;
	int				*screen;
	int				img_no;
	int				index_no;
	int				reso_no_x;
	int				reso_no_y;
	int				reso_so_x;
	int				reso_so_y;
	int				reso_we_x;
	int				reso_we_y;
	int				reso_ea_x;
	int				reso_ea_y;
	int				reso_sp_x;
	int				reso_sp_y;
	int				reso_g_x;
	int				reso_g_y;
	int				text;
	int				*data_north;
	int				*data_south;
	int				*data_west;
	int				*data_east;
	int				*data_print;
	int				*data_sprite;
	int				pp_north;
	int				pp_south;
	int				pp_west;
	int				pp_east;
	int				pp_sprite;
	int				sl_north;
	int				sl_south;
	int				sl_west;
	int				sl_east;
	int				sl_sprite;
	int				endian_no;
	int				endian_so;
	int				endian_we;
	int				endian_ea;
	int				endian_sp;
	int				line_height;
	int				key_a;
	int				key_s;
	int				key_d;
	int				key_w;
	int				key_left;
	int				key_right;
	int				map_x;
	int				map_y;
	int				hit;
	int				side;
	int				tex_h;
	int				tex_y;
	int				tex_w;
	int				tex_x;
	double			perp_wd;
	double			delta_x;
	double			delta_y;
	double			ppos_x;
	double			ppos_y;
	double			v_dir_x;
	double			v_dir_y;
	double			plane_x;
	double			plane_y;
	double			camera_x;
	double			ray_dir_x;
	double			ray_dir_y;
	double			step_x;
	double			step_y;
	double			side_dist_x;
	double			side_dist_y;
	double			z_buffer[2560];
	double			wall_x;
	char			c_buff;
	char			*north;
	char			*south;
	char			*west;
	char			*east;
	char			*sprite;
	char			**map;
	int				sprite_order[100];
	double			sprite_dis[2560];
	double			sprite_p_x;
	double			sprite_p_y;
	int				sprite_s_x;
	int				sprite_height;
	int				drawstartx;
	int				drawstarty;
	int				drawendx;
	int				drawendy;
	int				sprite_width;
}					t_cub3d;

int					get_next_line(int fd, char **line);
int					ft_check_static(char **save, char **line);
int					ft_find_line(char *str);
int					ft_handle_err(char **line, char *s, char *buff, int r);
char				*ft_strdup(const char *s);
char				*ft_strjoin(const char *s1, const char *s2);
char				*ft_strchr(const char *s, int c);
size_t				ft_strlen(const char *str);
char				*ft_strnew(char *str, char *dup);
int					key_press(int key, t_cub3d *cub);
int					key_release(int key, t_cub3d *cub);
void				ft_screen_move(t_cub3d *cub);
int					ft_skip(int fd, char buff[3], t_cub3d *cub);
int					ft_map_height(char **map);
int					ft_map_width(char **map);
int					get_color(int fd, t_cub3d *cub);
int					get_resolution(int fd, t_cub3d *cub);
int					ft_recup_texture(t_cub3d *cub);
void				ft_draw(int start, int end, int index, t_cub3d *cub);
void				side_texture(t_cub3d *cub, int i);
void				ft_height(t_cub3d *cub, int index);
void				ft_dd_algo(t_cub3d *cub);
void				ft_first_block(t_cub3d *cub);
int					ft_loop_game(t_cub3d *cub);
int					ft_make_game(t_cub3d *cub);
int					ft_check_char_map(char c, int player, t_cub3d *cub);
int					ft_check_board_map(t_cub3d *cub);
int					ft_check_map_size(t_cub3d *cub, int player);
int					ft_parsing_map(int fd, char buff[3], t_cub3d *cub);
void				ft_move_up(t_cub3d *cub);
void				ft_move_down(t_cub3d *cub);
void				ft_move_right(t_cub3d *cub);
void				ft_move_left(t_cub3d *cub);
void				ft_rotation_camera(t_cub3d *cub);
int					ft_is_valid(int fd, char buff[3], t_cub3d *cub);
int					ft_pars_resolution(int fd, t_cub3d *cub);
int					get_value(int fd, t_cub3d *cub);
int					ft_get_color(int fd, char buff[3], t_cub3d *cub);
int					get_value(int fd, t_cub3d *cub);
int					ft_pars_param(int fd, char buff[3], t_cub3d *cub);
int					ft_pars(int fd, t_cub3d *cub);
int					ft_texture_no(t_cub3d *cub);
int					ft_texture_so(t_cub3d *cub);
int					ft_texture_we(t_cub3d *cub);
int					ft_texture_es(t_cub3d *cub);
int					ft_texture_sp(t_cub3d *cub);
int					ft_check_cub(char *str);
int					ft_err_msg(int error);
void				ft_init_cub(t_cub3d *cub);
int					main(int argc, char **argv);
void				ft_choose_texture(t_cub3d *cub);
void				ft_texture(t_cub3d *cub);
void				ft_draw(int start, int end, int index, t_cub3d *cub);
int					ft_max(int a, int b);
void				ft_quit_game(t_cub3d *cub);
void				ft_init_vecteur_direction(char c, t_cub3d *cub);
void				ft_init_bmp(t_save *save);
int					ft_save(t_cub3d *cub, char *name);
void				ft_swap_int(int i, int j, t_cub3d *cub);
void				ft_swap_dbl(int i, int j, t_cub3d *cub);
void				ft_sprite(t_cub3d *cub);
void				ft_height_sprite(t_cub3d *cub, double transform_y);
void				ft_draw_sprite(t_cub3d *cub, double transform_y);
void				ft_sprite_order(t_cub3d *cub);
void				ft_sort_sprite(t_cub3d *cub);
void				ft_swap_int(int i, int j, t_cub3d *cub);
int					icon_exit(void *cub);

#endif
