/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/11 14:41:44 by ykliek            #+#    #+#             */
/*   Updated: 2019/05/11 14:41:46 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

 #include "fdf.h"

// int key_press(int keycode, void *mlx)
// {
// 	if (keycode == 49 || keycode == 53)
// 		exit(EXIT_SUCCESS);
// 	return (0);
// }

void	ft_lstadd_1(t_map **alst, t_map *new)
{
	if (alst && new)
	{
		new->next = (*alst);
		(*alst) = new;
	}
}


int		main(int argc, char **argv)
{
	void	*mlx;
	void	*mlx_wnd;
	void	*img;

	int 	bpp;
	int 	sz;
	int 	endian;
	char	*i_ptr;
	char	*line;
	int 	fd;
	int     i;
	t_map	map;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, &line) == 1)
		ft_lstadd_1(&map, read_map(line, i++));

	// printf("height: %d color: %s coord_x: %d coord_y: %d \n", map[0].height, map[0].color, map[0].x, map[0].y);

	// mlx = mlx_init();
	// mlx_wnd = mlx_new_window(mlx, WIDTH, HEIGHT, "first fdf");
	// img = mlx_new_image(mlx, WIDTH, HEIGHT);
	// i_ptr = mlx_get_data_addr(img, &bpp, &sz, &endian);
	// bpp /= 8;
	// for (int i = 0; i < 100; i++)
	// {
	// 	for (int j = 0; j < 100; j++)
	// 	{			
	// 		*(int *)(i_ptr + (i + j * WIDTH) * bpp) = 0xFF00FF;
	// 	}
	// }
	// mlx_put_image_to_window(mlx, mlx_wnd, img, 0, 0);
	// mlx_hook(mlx_wnd, 2, 0, key_press, mlx);
	// mlx_loop(mlx);

	// printf("%s\n", ft_strchr("12,0xFF00FF", ',') + 1);
	return (0);
}
