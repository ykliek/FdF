/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validator.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 19:40:07 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/20 19:40:08 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			check_length(t_map *map)
{
	t_map	*head;
	int		count;
	int		y;

	count = 0;
	head = map;
	y = map->content.y;
	map = map->next;
	while (map->next)
	{
		if (map->next->content.y == y)
		{
			count = map->content.y;
			break ;
		}
		map = map->next;
	}
	while (map->next)
	{
		if (map->next->content.y == y)
			if (map->content.y != count)
				return (1);
		map = map->next;
	}
	map = head;
	return (0);
}