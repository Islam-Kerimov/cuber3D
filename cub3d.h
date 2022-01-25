/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctanton <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/31 22:47:17 by ctanton           #+#    #+#             */
/*   Updated: 2021/04/04 18:25:45 by ctanton          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <math.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "mlx/mlx.h"
# define BUFFER_SIZE 1000

typedef struct	s_vars
{
	void			*mlx;
	void			*win;
	void			*img;
	char			*addr;
	int				bpp;
	int				line_len;
	int				endian;
}				t_vars;

typedef struct	s_buf
{
	unsigned int	**buf;
	double			*spbuf;
}				t_buf;

typedef struct	s_plr
{
	double			x_pos;
	double			y_pos;
	double			x_dir;
	double			y_dir;
	double			x_plane;
	double			y_plane;
	double			distance;
	int				flag_pos_plr;
	int				flag_dir;
}				t_plr;

typedef struct	s_ray
{
	int				s_line;
	int				e_line;
	double			cam_x;
	double			x_ray;
	double			y_ray;
	double			side_x;
	double			side_y;
	double			delta_x;
	double			delta_y;
	int				x_step;
	int				y_step;
	int				x_map;
	int				y_map;
	int				hit;
	int				side;
	int				h_line;
	unsigned int	color;
	int				tex_n;
	double			wall;
	int				tex_y;
	int				tex_x;
	double			pos_tex;
}				t_ray;

typedef struct	s_point
{
	int				x;
	int				y;
}				t_point;

typedef struct	s_sprite
{
	double			*x;
	double			*y;
	int				number_spr;
	double			*dist_sp;
	int				sprite;
	double			sp_x;
	double			sp_y;
	double			scale;
	double			turn_x;
	double			turn_y;
	int				sp_screen;
	int				h_sprite;
	int				start_y;
	int				end_y;
	int				sprite_w;
	int				start_x;
	int				end_x;
	int				sp_tex_x;
	int				sp_tex_y;
	unsigned int	color;
	double			temp;
	int				dis_tmp;
}				t_sprite;

typedef struct	s_size
{
	int				map_w;
	int				map_h;
	int				tex_w;
	int				tex_h;
	int				screen_w;
	int				screen_h;
	int				max_w;
	int				max_h;
}				t_size;

typedef struct	s_flag
{
	int				f_i;
	int				pos_map;
	int				last_pos_map;
	int				f_map;
	int				line_id;
	int				map_have;
	int				n;
	int				n1;
	int				n2;
	int				n3;
	int				n4;
	int				flag_one_player;
	int				flag_not_val;
	char			**argv;
	int				argc;
	int				k;
	int				last_k;
	int				f_d;
	int				color_r;
	int				color_g;
	int				color_b;
}				t_flag;

typedef struct	s_flag2
{
	int				f_r;
	int				f_s;
	int				f_f;
	int				f_c;
	int				f_no;
	int				f_so;
	int				f_we;
	int				f_ea;
	int				flag_for_c;
	int				flag_for_f;
}				t_flag2;

typedef struct	s_textur
{
	char			*no;
	char			*so;
	char			*we;
	char			*ea;
	char			*s;
	int				floor;
	int				ceiling;
}				t_textur;

typedef struct	s_txt
{
	void			*img_no;
	char			*addr_no;
	int				bpp_no;
	int				line_len_no;
	int				endian_no;
	void			*img_so;
	char			*addr_so;
	int				bpp_so;
	int				line_len_so;
	int				endian_so;
	void			*img_we;
	char			*addr_we;
	int				bpp_we;
	int				line_len_we;
	int				endian_we;
	void			*img_ea;
	char			*addr_ea;
	int				bpp_ea;
	int				line_len_ea;
	int				endian_ea;
	void			*img_s;
	char			*addr_s;
	int				bpp_s;
	int				line_len_s;
	int				endian_s;
}				t_txt;

typedef struct	s_bitmap
{
	unsigned char	bmppad;
	int				padd;
	int				header_size;
	int				info_size;
	int				file_size;
	unsigned char	file_head[14];
	unsigned char	info_head[40];
}				t_bitmap;

typedef struct	s_all
{
	t_vars			*vars;
	t_txt			*txt;
	t_plr			*plr;
	t_sprite		*sp;
	t_size			*size;
	t_textur		*texture;
	t_flag			*flag;
	t_flag2			*flag2;
	t_bitmap		*bitmap;
	t_point			*pos;
	t_buf			*buf;
	t_ray			*ray;
	char			**map;
	int				**world_map;
}				t_all;

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;

int				get_next_line(int fd, char **line);
void			ft_putchar_fd(char c, int fd);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			**ft_split(char const *s, char c);
long long int	ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_strtrim(char const *s1, char const *set);
size_t			ft_lstsize(t_list *lst);
t_list			*ft_lstnew(void *content);
void			ft_lstadd_back(t_list **lst, t_list *new);
char			*ft_strchr(char *s, int c);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strdup(const char *s1);
size_t			ft_strlen(const char *s);
void			*ft_calloc(size_t count, size_t size);
char			*ft_strnew(size_t size);
int				create_rgb(int r, int g, int b);
char			**ft_read_map(t_all *all);
void			ft_init_sprites(char **map, t_all *all);
void			ft_init_player(char **map, t_all *all);
int				key_press(int keycode, t_all *all);
int				ft_draw_screen(t_all *all);
void			my_mlx_pixel_put(t_vars *vars, int x, int y, int color);
void			ft_map(t_all *all);
int				close_all(t_all *all);
char			**ft_identifiers(char **identifiers, t_all *all);
void			len_map(char **identifiers, t_all *all);
char			**kill_spaces(char **identifiers);
char			**check_f_l_line(char **identifiers, t_all *all);
char			**check_f_l_line_for_one_or_zero(char **iden, t_all *all);
char			**check_zero(char **identifiers, t_all *all);
char			**check_2(char **identifiers, t_all *all);
void			ft_check_for_8(char **iden, t_all *all, int k);
char			**check_one_plr(char **identifiers, t_all *all);
char			**check_valid_simbol(char **identifiers, t_all *all);
char			**trim_map(char **identifiers, t_all *all);
char			**ft_cat_map(char **map, t_all *all, char **identifiers);
char			**pars_parsov(char **identifiers, t_all *all);
void			ft_parse_r(char *identifiers, t_all *all);
void			ft_parse_c(char *identifiers, t_all *all);
void			ft_parse_f(char *identifiers, t_all *all);
void			ft_parse_s(char *identifiers, t_all *all);
void			ft_parse_no(char *identifiers, t_all *all);
void			ft_parse_so(char *identifiers, t_all *all);
void			ft_parse_we(char *identifiers, t_all *all);
void			ft_parse_ea(char *identifiers, t_all *all);
void			ft_chech_txt_fotmat(char *s, t_all *all);
void			ft_bitmap(t_all *all);
void			ft_wall_cast(t_all *all, int w, int h);
void			ft_sprite_cast(t_all *all, int w, int h);
void			ft_init_struct(t_all *all);
int				main(int argc, char **argv);
char			**check_plr(char **iden, t_all *all);
void			ft_free_all(t_all *all);
void			ft_lineheight_text(t_all *all, int h);
void			ft_init_side_wall(t_all *all);
void			ft_dda(t_all *all);
void			ft_init_pos_ray_distanshion(t_all *all);
unsigned int	my_mlx_pixel_take(t_all *all, int x, int y);
void			ft_error(int error, t_all *all);
void			ft_free(char **tmp);
void			check_comma(char *identifiers, t_all *all);
void			free_world_map_sprites(t_all *all);

#endif
