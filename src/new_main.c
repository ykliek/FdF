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

void	move(t_mlx *fdf, int keycode)
{
	if (keycode == 123)
		fdf->cam->start_y -= 5;
	if (keycode == 124)		
		fdf->cam->start_y += 5;
	if (keycode == 125)
		fdf->cam->start_x += 5;
	if (keycode == 126)		
		fdf->cam->start_x -= 5;
}

int		key_press(int keycode, t_mlx *fdf)
{
	if (keycode == 49 || keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		move(fdf, keycode);
		image(fdf);
	}
	// else
		// printf("%d\n", keycode);
	return (0);
}

int		main(int argc, char **argv)
{
	int		fd;
	t_mlx	fdf;
	t_map	*map;
	t_map	*end;

	fd = open(argv[1], O_RDONLY);
	// map = write_map(fd);
	end = getLast(map);
	fdf.mlx = mlx_init();
	fdf.mlx_wnd = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FdF");
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	fdf.i_ptr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.sz, &fdf.endian);
	fdf.bpp /= 8;
	fdf.cam = (t_cam *)malloc(sizeof(t_cam));
	fdf.cam->start_x = 100;
	fdf.cam->start_y = 100;
	fdf.map = write_map(fd);
	image(&fdf);
	mlx_hook(fdf.mlx_wnd, 2, 0, key_press, &fdf);
	mlx_loop(fdf.mlx);

	return (0);
}
