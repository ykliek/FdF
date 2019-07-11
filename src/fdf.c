/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:42:00 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/11 14:42:02 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void iso(int *x, int *y, int z)
{
    int previous_x;
    int previous_y;

    previous_x = *x;
    previous_y = *y;
    *x = (previous_x - previous_y) * cos(0.523599) + 600;
    *y = -z + (previous_x + previous_y) * sin(0.523599) + 200;
}

t_value 		curr_dot(t_map *begin_list, int x, int y)
{
	t_value		content;

	while (begin_list)
	{
		if (begin_list->content.x == x && begin_list->content.y == y)
			return(begin_list->content);
		begin_list = begin_list->next;
	}
	return (content);
}

t_draw		get_double(t_map *map, t_value content)
{
	t_draw	values;

	values.add = map->content.height;
	values.cur_h = map->content.height;
	values.col = map->content.color;
	values.new_height = content.height;
	return (values);
}

void		put_pixel(t_mlx *fdf, t_params val, t_draw values)
{
	t_params tmp;

	tmp = val;
	(fdf->izo_mod == 0) ? : iso(&tmp.y, &tmp.x, (int)values.add);
	tmp.y += fdf->cam->start_y;
	tmp.x += fdf->cam->start_x;
	if (tmp.y >= 0 && tmp.y < WIDTH && tmp.x >= 0 && tmp.x < HEIGHT)
		*(int *)(fdf->i_ptr + ((tmp.y + (tmp.x  + (int)values.add) * WIDTH) * tmp.bpp)) = values.col;
}

int		calc_color(int color1, int color2, double par, int len)
{
	t_color c;
	t_color c2;
	c2 = parse_color(color1);
	t_color c1;
	c1 = parse_color(color2);
	double percent = par / len;

	c.r = (int)(c1.r * (1 - percent) + c2.r * percent);
	c.g = (int)(c1.g * (1 - percent) + c2.g * percent);
	c.b = (int)(c1.b * (1 - percent) + c2.b * percent);
	c.color = (c.r << 16) + (c.g << 8) + c.b;
	return (c.color);
}

void		draw_y(t_mlx *fdf, t_params val, t_map *map, t_map *head)
{
	t_draw		values;
	t_params	new;
	t_value		data;
	t_map		*end;

	values.count = 0;
	new.y = map->next->content.y;
	end = getLast(map);
	data = curr_dot(head, val.x, new.y);
	values = get_double(map, data);
	new.x = new.y - val.y;
	// if (values.cur_h > values.new_height)
	// {
	// 	new.x += values.cur_h;
	// 	new.y += values.cur_h;
	// }
	// if (values.cur_h < values.new_height)
	// {
	// 	new.x += values.new_height;
	// 	new.y += values.new_height;
	// }
	if (val.y < end->content.y)
		while (val.y <= new.y)
		{
			values.col = calc_color(data.color, map->content.color, values.count, new.x);
			values.add = 0;
			put_pixel(fdf, val, values);
			if (values.add > values.new_height)
				values.add -= values.cur_h / new.x;
			if (values.add < values.new_height)
				values.add += values.new_height / new.x;
			values.count++;
			val.y++;
		}
}

void		draw_x(t_mlx *fdf, t_params val, t_map *map, t_map *head)
{
	t_draw		values;
	t_params	new;
	t_value		data;
	t_map		*end;

	values.count = 0;
	new.x = find_under(map, val.y);
	end = getLast(map);
	data = curr_dot(head, new.x, val.y);
	values = get_double(map, data);
	new.y = new.x - val.x; // length between two points
	if (val.x < end->content.x)
		while (val.x <= new.x)
		{
			values.col = calc_color(data.color, map->content.color, values.count, new.y);
			put_pixel(fdf, val, values);
			if (values.add > values.new_height)
				values.add -= values.cur_h / new.y;
			if (values.add < values.new_height)
				values.add += values.new_height / new.y;
			values.count++;
			val.x++;
		}
}

t_map		*write_map(int fd)
{
	int		i;
	char	*line;
	t_map	*map;

	i = 0;
	map = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		lst_add(&map, read_map(line, i));
		i++;
	}
	return (map);
}

void		image(t_mlx	*fdf)
{
	t_params	val;
	t_map		*head;
	t_map		*last_xy;


	mlx_destroy_image(fdf->mlx, fdf->img);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->i_ptr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->sz, &fdf->endian);
	fdf->bpp /= 8;
	head = fdf->map;
	val.x = fdf->map->content.x;
	val.y = fdf->map->content.y;
	val.z = fdf->map->content.height;
	val.bpp = fdf->bpp;
	while (fdf->map->next)
	{
		draw_y(fdf, val, fdf->map, head);
		draw_x(fdf, val, fdf->map, head);
		fdf->map = fdf->map->next;
		val.y = fdf->map->content.y;
		val.x = fdf->map->content.x;
		val.z = fdf->map->content.height;
	}
	fdf->map = head;
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_wnd, fdf->img, 0, 0);
}