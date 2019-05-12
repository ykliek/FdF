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


# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft.h"

# define WIDTH 1920
# define HEIGHT 1080

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

t_map				*read_map(char *line, int j);

void				push(t_map	**head, t_value	data);

void				lst_add(t_map **head, t_map	*add);
 
void				deleteList(t_map	**head);

void				pushBack(t_map	*head,	t_value	data);

t_map				*getLast(t_map	*head);

int					ft_atoi_base(char	*str, int	base);

# endif
