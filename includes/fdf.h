/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:41:51 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/11 14:41:53 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FDF_H
# define FDF_H

# include "mlx.h"
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"

# define WIDTH 1280
# define HEIGHT 800

# define NUM(x) (x > 0) ? 1 : -1

typedef	struct	s_color
{
	int			r;
	int			g;
	int			b;
	int			color;
}				t_color;

typedef	struct	s_value
{
	int			height;
	int			color;
	int			x;
	int			y;
	int			id;
}				t_value;

typedef	struct		s_map
{
	t_value			content;
	struct s_map	*next;
}					t_map;


typedef	struct		s_params
{
	int				x;
	int				y;
	int				z;
	int				c1;
	int				new_x;
	int				new_y;
	int				new_z;
	int 			c2;
	int				end_x;
	int				end_y;
	int				tmp;
}					t_params;

typedef	struct		s_cam
{
	int				start_x;
	int				start_y;
}					t_cam;

typedef	struct		s_mlx
{
	t_cam			*cam;
	t_map			*map;
	t_map			*end;
	int				sz;
	int				bpp;
	int				lamp;
	int				scale;
	int				color;
	int 			endian;
	int				button;
	int				izo_mod;
	int				color_t;
	int				spin_mode;
	void			*mlx;
	void			*img;
	void			*mlx_wnd;
	char			*i_ptr;
	double			up;
	double			alfa;
	double			alfa2;
}					t_mlx;

typedef	struct		s_draw
{
	int				col;
	int				length;
	double			add;
	double			step;
	double			val_x;
	double			cur_h;
	double			count;
	double			new_height;
}					t_draw;

void				image(t_mlx *fdf);

t_map				*write_map(int fd);

t_map				*write_map(int fd);

void				ret_scale(t_mlx *fdf);

void				ret_scale(t_mlx *fdf);

t_color				parse_color(int color);

t_map				*getLast(t_map	*head);

void				make_scale(t_mlx *fdf);

void				make_izo(t_params *izo);

int					define_scale(t_mlx fdf);

int					check_length(t_map *map);

void				set_defaults(t_mlx *fdf);

void				iso(int *x, int *y, int z);

void				deleteList(t_map *head);

t_map				*read_map(char *line, int j);

void				move(t_mlx *fdf, int keycode);

void				zoom(int keycode, t_mlx *fdf);

t_map				*find_under(t_map *map, int y);

void				draw_y(t_mlx *fdf, t_map *head);

void				draw_x(t_mlx *fdf, t_map *head);

void				push(t_map	**head, t_value	data);

void				lst_add(t_map **head, t_map	*add);

int					key_press(int keycode, t_mlx *fdf);

void				pushBack(t_map	*head,	t_value	data);

int					ft_atoi_base(char	*str, int	base);

void				change_color_btype(int keycode, t_mlx *fdf);

void				put_pixel(t_mlx *fdf, int x, int y, int color);

int					mouse_press(int button, int x, int y, t_mlx *fdf);

int					calc_color(int color1, int color2, double percent);

void				spin_figure(t_mlx *fdf, double *x, double *y, int z, t_params dots);

# endif
