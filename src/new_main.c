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

int		main(int argc, char **argv)
{
	int 	fd;
	t_mlx	fdf;
	t_map	*map;
	t_map	*end;

	end = getLast(map);
	fd = open(argv[1], O_RDONLY);
	map = write_map(fd);
	fdf.mlx = mlx_init();
	fdf.mlx_wnd = mlx_new_window(fdf.mlx, WIDTH, HEIGHT, "FdF");
	fdf.img = mlx_new_image(fdf.mlx, WIDTH, HEIGHT);
	fdf.i_ptr = mlx_get_data_addr(fdf.img, &fdf.bpp, &fdf.sz, &fdf.endian);
	fdf.bpp /= 8;
	fdf(fdf.i_ptr, fdf.map, fdf.bpp);
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_wnd, fdf.img, WIDTH / 2 - end->content.x / 2, HEIGHT / 2 - end->content.y / 2);
	mlx_hook(fdf.mlx_wnd, 2, 0, key_press, fdf.mlx);
	mlx_loop(fdf.mlx);
	return (0);
}
