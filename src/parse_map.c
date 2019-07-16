/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 17:35:54 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/11 17:35:55 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



t_map	*read_map(char *line, int j)
{
	t_map	*map;
	t_value	data;
	char	**str;
	int		i;

	map = NULL;
	i = 0;
	str = ft_strsplit(line, ' ');
	while (str[i])
	{
		data.height = ft_atoi(str[i]);
		if (ft_strchr(str[i], ','))
			data.color = ft_atoi_base(ft_strchr(str[i], ',') + 1, 16);
		else
			data.color = ft_atoi_base("0xFFFFFF", 16);
		data.x = j * SCALE;
		data.y = i * SCALE;
		if (j == 0 || !map)
			push(&map, data);
		else
			pushBack(map, data);
		i++;
	}
	return (map);
}

t_color		parse_color(int color)
{
	t_color c;

	c.r = color >> 16;
	color -= c.r << 16;
	c.g = color >> 8;
	color -= c.g << 8;
	c.b = color;
	return (c);
}