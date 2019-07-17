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
	fdf.cam->start_x = 100;
	fdf.cam->start_y = 100;
	fdf.scale = 50;
	fdf.lamp = 0;
	fdf.color_t = 0;
	fdf.alfa = 0;
	fdf.izo_mod = 0;
	fdf.map = write_map(fd);
	image(&fdf);
	mlx_hook(fdf.mlx_wnd, 2, 0, key_press, &fdf);
	mlx_loop(fdf.mlx);
	return (0);
}
