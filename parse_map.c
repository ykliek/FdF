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

t_map	read_map(char *line, int j)
{
	t_map	map;
	char	**str;
	int		i[4];

	i[0] = 0;
	str = ft_strsplit(line, ' ');
	while (str[i[0]])
	{
		map.height = ft_atoi(str[i[0]]);
		if (ft_strchr(str[i[0]], ','))
			map.color = ft_strchr(str[i[0]], ',') + 1;
		map.x = j;
		map.y = i[0];
		i[0]++;
		map.next = &map;
	}
	return (map);
}
