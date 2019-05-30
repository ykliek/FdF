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
		data.x = j * 50;
		data.y = i * 50;
		if (j == 0 || !map)
			push(&map, data);
		else
			pushBack(map, data);
		i++;
	}
	return (map);
}