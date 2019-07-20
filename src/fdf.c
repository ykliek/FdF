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

#include <time.h> // Delete

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
	y += fdf->cam->start_y + (WIDTH / 2);
	x += fdf->cam->start_x + (HEIGHT / 2);
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
	clock_t	begin;
	clock_t	end;
	clock_t	start;
	begin = clock();
	start = clock();
	while (fdf->map->next)
	{
		draw_y(fdf, head);
		draw_x(fdf, head);
		end = clock();
		printf("Time: %.2f\t%.2f ms\n", (double)(end - begin) / CLOCKS_PER_SEC * 1000,
				(double)(end - start) / CLOCKS_PER_SEC * 1000);
		begin = clock();
		fdf->map = fdf->map->next;
	}
	fdf->map = head;
	mlx_put_image_to_window(fdf->mlx, fdf->mlx_wnd, fdf->img, 0, 0);
}
