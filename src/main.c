/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_main.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/18 19:25:09 by ykliek            #+#    #+#             */
/*   Updated: 2019/06/18 19:25:10 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int 		define_scale(t_mlx		fdf)
{
	int 		scale;
	t_map		*end;


	end = getLast(fdf.map);
	scale = (WIDTH / end->content.y >= HEIGHT / end->content.x) ?
		HEIGHT / end->content.x : WIDTH / end->content.y;
	return (scale);
}

int		close_wnd(void	*param)
{
	(void)param;
	exit(0);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_mlx	fdf;

	fd = open(argv[1], O_RDONLY);
	fdf.mlx = mlx_init();
	fdf.mlx_wnd = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FdF");
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	fdf.i_ptr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.sz, &fdf.endian);
	fdf.bpp /= 8;
	fdf.cam = (t_cam *)malloc(sizeof(t_cam));
	fdf.cam->start_x = 0;
	fdf.cam->start_y = 0;
	fdf.lamp = 0;
	fdf.color_t = 0;
	fdf.alfa = 0;
	fdf.izo_mod = 0;
	fdf.up = 0;
	fdf.map = write_map(fd);
	fdf.scale = define_scale(fdf);
	image(&fdf);
	mlx_hook(fdf.mlx_wnd, 2, 0, key_press, &fdf);
	mlx_hook(fdf.mlx_wnd, 4, 0, mouse_press, &fdf);
	mlx_hook(fdf.mlx_wnd, 17, 0, close_wnd, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
