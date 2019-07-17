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
// # define WIDTH 1920
// # define HEIGHT 1366

typedef struct	s_color
{
	int r;
	int g;
	int b;
	int color;
}				t_color;

typedef	struct 	s_value
{
	int			height;
	int			color;
	int			x;
	int			y;
}				t_value;

typedef	struct 		s_map
{
	t_value			content;
	struct s_map	*next;
}					t_map;

typedef struct 		s_params
{
	int				x;
	int				y;
	int				z;
	int				bpp;
	int				tmp;
}					t_params;

typedef struct		s_cam
{
	int start_x;
	int start_y;
}					t_cam;

typedef struct 		s_mlx
{
	void	*mlx;
	void	*mlx_wnd;
	void	*img;
	t_cam	*cam;
	t_map	*map;
	int		izo_mod;
	int 	bpp;
	int		color_t;
	int 	sz;
	int		scale;
	int		lamp;
	int 	endian;
	char	*i_ptr;
	int		spin_mode;
	double		alfa;
}					t_mlx;

typedef struct 		s_draw
{
	double			step;
	double			val_x;
	int				length;
	double			add;
	double			cur_h;
	double			count;
	int				col;
	double			new_height;
}					t_draw;

t_map				*read_map(char *line, int j);

void				push(t_map	**head, t_value	data);

void				lst_add(t_map **head, t_map	*add);
 
void				deleteList(t_map	**head);

void				pushBack(t_map	*head,	t_value	data);

t_map				*getLast(t_map	*head);

int					ft_atoi_base(char	*str, int	base);

void				image(t_mlx *fdf);

t_map				*write_map(int fd);

int					find_under(t_map *map, int y);

void				make_izo(t_params *izo);

t_color				parse_color(int color);

int					key_press(int keycode, t_mlx *fdf);

void				change_color_btype(int keycode, t_mlx *fdf);

void				ret_scale(t_mlx *fdf);

void				move(t_mlx *fdf, int keycode);

void				zoom(int keycode, t_mlx *fdf);

void				ret_scale(t_mlx *fdf);

t_map				*write_map(int fd);

void				make_scale(t_mlx *fdf);

int					calc_color(int color1, int color2, t_draw	values);

void 				spin_figure(t_mlx *fdf, int *x, int *y, int z);

void				iso(int *x, int *y, int z);

void				draw_y(t_mlx *fdf, t_params val, t_map *map, t_map *head);

void				draw_x(t_mlx *fdf, t_params val, t_map *map, t_map *head);

void				put_pixel(t_mlx *fdf, t_params val, t_draw values);

# endif
