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

void		put_pixel(t_mlx *fdf, t_params val, t_draw values)
{
	t_params tmp;

	tmp = val;
	spin_figure(fdf, &tmp.y, &tmp.x, (int)values.add);
	tmp.y += fdf->cam->start_y;
	tmp.x += fdf->cam->start_x;
	(fdf->izo_mod == 0) ? : iso(&tmp.y, &tmp.x, 0);
	if (tmp.y >= 0 && tmp.y < WIDTH && tmp.x >= 0 && tmp.x < HEIGHT)
		*(int *)(fdf->i_ptr + ((tmp.y + tmp.x * WIDTH) * tmp.bpp)) = values.col;
}

void		image(t_mlx	*fdf)
{
	t_params	val;
	t_map		*head;

	mlx_destroy_image(fdf->mlx, fdf->img);
	head = fdf->map;
	(fdf->lamp == 1) ? : make_scale(fdf);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->i_ptr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->sz, &fdf->endian);
	fdf->bpp /= 8;
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
