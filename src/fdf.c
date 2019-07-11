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

t_value	make_izo(t_value izo)
{
	int		x_before;
	int		y_before;

	x_before = izo.x;
	y_before = izo.y;
	izo.y = (y_before - x_before) * cos(0.523599);
	izo.x = -izo.height + (y_before - x_before) * sin(0.523599);
	return (izo);
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

void		draw_y(char	*i_ptr, t_params val, t_map *map, t_map *head)
{
	t_draw		values;
	t_params	new;
	t_value		data;
	t_map		*end;

	values.count = 0;
	// new.x = map->next->content.x;
	new.y = map->next->content.y;
	end = getLast(map);
	data = curr_dot(head, val.x, new.y);
	values = get_double(map, data);
	new.x = new.y - val.y;
	if (val.y < end->content.y)
		while (val.y <= new.y)
		{
			values.col = (int)(map->content.color * (1 - values.count / new.x) 
				+ (values.count / new.x) * data.color);
			*(int *)(i_ptr + (((val.y + (int)values.add)
			 + val.x * WIDTH) * val.bpp)) = values.col;
			if (values.add > values.new_height)
				values.add -= values.cur_h / new.x;
			if (values.add < values.new_height)
				values.add += values.new_height / new.x;
			values.count++;
			val.y++;
		}
}

void		draw_x(char	*i_ptr, t_params val, t_map *map, t_map *head)
{
	t_draw		values;
	t_params	new;
	t_value		data;
	t_map		*end;

	values.count = 0;
	new.x = find_under(map, val.y);
	// new.x = val.x + SCALE;
	// new.y = map->next->content.y;
	end = getLast(map);
	data = curr_dot(head, new.x, val.y);
	values = get_double(map, data);
	new.y = new.x - val.x; // length between two points
	if (val.x < end->content.x)
		while (val.x <= new.x)
		{
			values.col = (int)(map->content.color * (1 - values.count / new.y)
				+ (values.count / new.y) * data.color);
			*(int *)(i_ptr + (((val.y + (int)values.add)
			 + val.x * WIDTH) * val.bpp)) = values.col;
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

void		image(char *i_ptr, t_map *map, int bpp)
{
	t_params	val;
	t_map		*head;
	t_map		*last_xy;

	head = map;
	last_xy = getLast(map);
	val.x = map->content.x;
	val.y = map->content.y;
	val.bpp = bpp;
	while (map->next)
	{
		draw_y(i_ptr, val, map, head);
		draw_x(i_ptr, val, map, head);
		map = map->next;
		val.y = map->content.y;
		val.x = map->content.x;
	}
}