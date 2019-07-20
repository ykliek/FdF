/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tool.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 09:55:04 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/17 09:55:06 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_map	*write_map(int fd)
{
	int		i;
	char	*line;
	t_map	*map;

	i = 0;
	map = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		if (ft_strlen(ft_strtrim(line)) == 0)
			return (NULL);
		lst_add(&map, read_map(line, i));
		i++;
	}
	return (map);
}

void	make_scale(t_mlx *fdf)
{
	t_map	*head;

	head = fdf->map;
	while (fdf->map != NULL)
	{
		fdf->map->content.x *= fdf->scale;
		fdf->map->content.y *= fdf->scale;
		fdf->map = fdf->map->next;
	}
	fdf->map = head;
}

int		calc_color(int color1, int color2, double percent)
{
	t_color		c;
	t_color		c2;
	t_color		c1;

	c1 = parse_color(color2);
	c2 = parse_color(color1);
	c.r = (int)(c1.r * (1 - percent) + c2.r * percent);
	c.g = (int)(c1.g * (1 - percent) + c2.g * percent);
	c.b = (int)(c1.b * (1 - percent) + c2.b * percent);
	c.color = (c.r << 16) + (c.g << 8) + c.b;
	return (c.color);
}

void	spin_figure(t_mlx *fdf, double *x, double *y, int z, t_params dots)
{
	int		previous_x;
	int		previous_y;

	previous_x = *x;
	previous_y= *y;
	*x = (previous_x - dots.end_x / 2) * cos(fdf->alfa2) + z * sin(fdf->alfa2); // поворот по осі У
	*y = (previous_y - dots.end_y / 2) * cos(fdf->alfa) + z * sin(fdf->alfa); // поворот по осі X
}

void	iso(int *x, int *y, int z)
{
	int		previous_x;
	int		previous_y;

	previous_x = *x;
	previous_y = *y;
	*x = (-z + (previous_x - previous_y)) * cos(0.523599) * 0.7;
	*y = (previous_x + previous_y) * sin(0.523599) * 0.7;
}
