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


// #include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft/libft.h"
#include "Get_Next_Line/get_next_line.h"

# define WIDTH 1920
# define HEIGHT 1080

typedef	struct 		s_map
{
	int				height;
	char			*color;
	int				x;
	int				y;
	struct s_map	*next;
}					t_map;

 t_map	read_map(char *line, int j);

# endif
