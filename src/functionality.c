/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functionality.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 09:28:19 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/17 09:28:20 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	move(t_mlx *fdf, int keycode)
{
	if (keycode == 123)
		fdf->cam->start_y -= 5;
	if (keycode == 124)		
		fdf->cam->start_y += 5;
	if (keycode == 125)
		fdf->cam->start_x += 5;
	if (keycode == 126)		
		fdf->cam->start_x -= 5;
}

void	zoom(int keycode, t_mlx *fdf)
{
	t_map	*head;
	int 	x;
	int 	y;
	int		tmp;

	head = fdf->map;
	fdf->map = fdf->end;
	x = fdf->map->content.x * fdf->scale;
	y = fdf->map->content.y * fdf->scale;
	tmp = fdf->scale;
	if (keycode == 69)
	{
		fdf->scale *= 1.1;
		fdf->scale = (fdf->scale == tmp) ? fdf->scale + 1 : fdf->scale;
	}
	if (keycode == 78)
	{
		fdf->scale /= 1.1;
		fdf->scale = (fdf->scale == 0) ? 1 : fdf->scale;
	}
	fdf->map = head; 
}

void	change_color(t_mlx *fdf, int color, int type)
{
	t_map *head;

	head = fdf->map;
	while (fdf->map != NULL)
	{
		if (fdf->map->content.height == 0 && type == 0)
			fdf->map->content.color = color;
		if (fdf->map->content.height > 0 && type == 1)
			fdf->map->content.color = color;
		if (fdf->map->content.height < 0 && type == 2)
			fdf->map->content.color = color;
		fdf->map = fdf->map->next;
	}
	fdf->map = head;
}

void change_color_btype(int keycode, t_mlx *fdf)
{
	if (keycode == 83)
		change_color(fdf, ft_atoi_base("0x00ffff", 16), fdf->color_t);
	if (keycode == 84)
		change_color(fdf, ft_atoi_base("0x000000", 16), fdf->color_t);
	if (keycode == 85)
		change_color(fdf, ft_atoi_base("0xff00ff", 16), fdf->color_t);
	if (keycode == 86)
		change_color(fdf, ft_atoi_base("0x808080", 16), fdf->color_t);
	if (keycode == 87)
		change_color(fdf, ft_atoi_base("0x00ff00", 16), fdf->color_t);
	if (keycode == 88)
		change_color(fdf, ft_atoi_base("0xff0000", 16), fdf->color_t);
	if (keycode == 89)
		change_color(fdf, ft_atoi_base("0xffffff", 16), fdf->color_t);
	if (keycode == 90)
		change_color(fdf, ft_atoi_base("0xffff00", 16), fdf->color_t);
	if (keycode == 91)
		change_color(fdf, ft_atoi_base("0xffa500", 16), fdf->color_t);
}
