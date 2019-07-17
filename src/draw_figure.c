/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_figure.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 09:53:08 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/17 09:53:09 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_draw		get_double(t_map *map, t_value content)
{
	t_draw	values;

	values.add = map->content.height;
	values.cur_h = map->content.height;
	values.col = map->content.color;
	values.new_height = content.height;
	return (values);
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

void		draw_y(t_mlx *fdf, t_params val, t_map *map, t_map *head)
{
	t_draw		values;
	t_params	new;
	t_value		data;
	t_map		*end;

	new.y = map->next->content.y;
	end = getLast(map);
	data = curr_dot(head, val.x, new.y);
	values = get_double(map, data);
    values.count = 0;
    values.length = new.y - val.y;
	values.step = (values.cur_h != values.new_height) ? 
	(values.new_height - values.cur_h) / values.length : 0;
	values.val_x = val.x;
	values.val_x -= values.cur_h;
	if (val.y < end->content.y)
		while (val.y <= new.y)
		{
			values.val_x -= values.step;
			val.x = (int)values.val_x;
			values.col = calc_color(data.color, map->content.color, values);
			put_pixel(fdf, val, values);
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

	new.x = find_under(map, val.y);
	end = getLast(map);
	data = curr_dot(head, new.x, val.y);
	values = get_double(map, data);
	values.count = 0;
	val.x -= values.cur_h;
	new.x -= values.new_height;
	values.length = new.x - val.x;
	if (val.x < end->content.x)
		while (val.x <= new.x)
		{
			values.col = calc_color(data.color, map->content.color, values);
			put_pixel(fdf, val, values);
			values.count++;
			val.x++;
		}
}
