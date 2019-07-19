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


void		draw_line(t_mlx *fdf, t_params dots)
{
	int i;
	int step;
	double x;
	double y;
	double	percent;
	int		color;

	i = 0;
	step = (int)fmax(abs((dots.new_x - dots.new_z * fdf->scale / 25) - (dots.x - dots.z * fdf->scale / 25)), abs(dots.y - dots.new_y));
	// printf("X: %d->%d\tY: %d->%d\tZ: %d->%d\n", dots.x, dots.new_x, dots.y, dots.new_y, dots.z, dots.new_z);
	while (i < step)
	{
		percent = (double)i / step;
		x = ((dots.x - dots.z * fdf->scale / 25) * (step - i) + (dots.new_x - dots.new_z * fdf->scale / 25) * i) / step;
		y = (dots.y * (step - i) + dots.new_y * i) / step;
		color = calc_color(dots.c2, dots.c1, percent);
		put_pixel(fdf, (int)x, (int)y, color);
		i++;
	}
}

void		draw_y(t_mlx *fdf, t_map *head)
{
    t_params dots;

    if (fdf->map->next)
    {
        dots.x = fdf->map->content.x;
        dots.y = fdf->map->content.y;
        dots.z = fdf->map->content.height;
        dots.c1 = fdf->map->content.color;
        dots.new_x = fdf->map->content.x;
        dots.new_y = fdf->map->next->content.y;
        dots.new_z = fdf->map->next->content.height;
        dots.c2 = fdf->map->next->content.color;
		if (dots.new_y != 0)
		{
			(fdf->izo_mod == 0) ? : iso(&dots.y, &dots.x, 0);
			(fdf->izo_mod == 0) ? : iso(&dots.new_y, &dots.new_x, 0);
			draw_line(fdf, dots);
		}
    }
}

 void		draw_x(t_mlx *fdf, t_map *head)
 {
        t_params dots;
        t_value     next_dots;

        if (fdf->map->next)
        {
            dots.x = fdf->map->content.x;
            dots.y = fdf->map->content.y;
            dots.z = fdf->map->content.height;
            dots.c1 = fdf->map->content.color;
            dots.new_x = find_under(fdf->map, dots.y);
            dots.new_y = fdf->map->content.y;
            next_dots = curr_dot(head, dots.new_x, dots.new_y);
            dots.new_z = next_dots.height;
            dots.c2 = next_dots.color;
            if (dots.new_x != 0)
            {
				(fdf->izo_mod == 0) ? : iso(&dots.y, &dots.x, 0);
				(fdf->izo_mod == 0) ? : iso(&dots.new_y, &dots.new_x, 0);
				draw_line(fdf, dots);
			}
        }
 }

