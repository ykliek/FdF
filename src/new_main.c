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

int		key_press(int keycode, void *mlx)
{
	if (keycode == 49 || keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
}

int		main(int argc, char **argv)
{
	int 	fd;
	t_mlx	fdf;
	t_map	*map;
	t_map	*end;

	fd = open(argv[1], O_RDONLY);
	map = write_map(fd);
	end = getLast(map);
	fdf.mlx = mlx_init();
	fdf.mlx_wnd = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FdF");
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	fdf.i_ptr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.sz, &fdf.endian);
	fdf.bpp /= 8;
	image(fdf.i_ptr, map, fdf.bpp);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_wnd, fdf.img, WIDTH / 2 - end->content.x, HEIGHT / 2 - end->content.y / 2);
	mlx_hook(fdf.mlx_wnd, 2, 0, key_press, fdf.mlx);
	mlx_loop(fdf.mlx);
	printf("%s\n", "test");
	return (0);
}
