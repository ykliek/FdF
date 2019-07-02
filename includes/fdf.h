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
# define SCALE 25

typedef	struct 	s_value
{
	int			height;
	double			color;
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
	int				bpp;
}					t_params;

typedef struct 		s_mlx
{
	void	*mlx;
	void	*mlx_wnd;
	void	*img;
	int 	bpp;
	int 	sz;
	int 	endian;
	char	*i_ptr;
}					t_mlx;

typedef struct 		s_draw
{
	double			add;
	double			cur_h;
	double			count;
	double			col;
	double			new_height;
}					t_draw;

t_map				*read_map(char *line, int j);

void				push(t_map	**head, t_value	data);

void				lst_add(t_map **head, t_map	*add);
 
void				deleteList(t_map	**head);

void				pushBack(t_map	*head,	t_value	data);

t_map				*getLast(t_map	*head);

int					ft_atoi_base(char	*str, int	base);

void				image(char *i_ptr, t_map *map, int bpp);

t_map				*write_map(int fd);

# endif
