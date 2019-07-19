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

void		growth(t_mlx *fdf)
{
	t_map	*head;

	head = fdf->map;
	while (fdf->map != NULL)
	{
		if(fdf->map->content.id == 1)
			fdf->map->content.height += fdf->up;
		if(fdf->map->content.id == -1)
			fdf->map->content.height -= fdf->up;
		fdf->map = fdf->map->next;
	}
	fdf->map = head;
}

void		put_pixel(t_mlx *fdf, int x, int y, int color)
{
	// t_params tmp;

	// tmp = val;
	// spin_figure(fdf, &tmp.y, &tmp.x, tmp.z);
	y += fdf->cam->start_y;
	x += fdf->cam->start_x;
//	 (fdf->izo_mod == 0) ? : iso(&y, &x, 0);
	if (y >= 0 && y < WIDTH && x >= 0 && x < HEIGHT)
		*(int *)(fdf->i_ptr + ((y + x * WIDTH) * fdf->bpp)) = color;
}

void		image(t_mlx	*fdf)
{
	t_map		*head;

	mlx_destroy_image(fdf->mlx, fdf->img);
	growth(fdf);
	head = fdf->map;
	(fdf->lamp == 1) ? : make_scale(fdf);
	fdf->img = mlx_new_image(fdf->mlx, WIDTH, HEIGHT);
	fdf->i_ptr = mlx_get_data_addr(fdf->img, &fdf->bpp, &fdf->sz, &fdf->endian);
	fdf->bpp /= 8;
	while (fdf->map->next)
	{
		draw_y(fdf, head);
		 draw_x(fdf, head);
		fdf->map = fdf->map->next;
	}
	fdf->map = head;
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_wnd, fdf->img, 0, 0);
}
