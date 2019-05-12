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

void	test_map(t_map *map)
{
	int count;
	int  i;

	count = 0;
	i = 0;
	while (map->next)
	{
		if (map->content.height != 0)
			count++;
		ft_printf("X = %d Y = %d COLOR = %d      ", map->content.x, map->content.y, map->content.color);
		if (i % 10 == 0)
			ft_printf("\n");
		map = map->next;
	}
	ft_printf("%d \n", count);
}

int		key_press(int keycode, void *mlx)
{
	if (keycode == 49 || keycode == 53)
		exit(EXIT_SUCCESS);
	return (0);
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
	int j;
	t_map	*map;
	t_map 	*tmp;

	i = 0;
	fd = open(argv[1], O_RDONLY);
	map = NULL;
	while (get_next_line(fd, &line) == 1)
	{
		lst_add(&map, read_map(line, i));
		i++;
	}

	// test_map(map);
	tmp = getLast(map);
	mlx = mlx_init();
	mlx_wnd = mlx_new_window(mlx, WIDTH, HEIGHT, "first fdf");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	i_ptr = mlx_get_data_addr(img, &bpp, &sz, &endian);
	bpp /= 8;
	// for (i = 0; i < 500; i++)
	// {
	// 	for (int j = 0; j < 500; j++)
	// 	{
	// 		*(int *)(i_ptr + (i + j * 1920) * bpp) = 0xFF00FF;
	// 	}
	// }
	// printf("%d\n", tmp->content.y);
	i = 0;
	while (i <= tmp->content.y)
	{
		j = 0;
		while (j <= tmp->content.x)
		{
			if (i % 50 == 0 || j % 50 == 0)
				*(int *)(i_ptr + ((i + j * WIDTH) * bpp)) = map->content.color;
			if (j == map->content.x && i == map->content.y)
			{
				*(int *)(i_ptr + ((i + j * WIDTH) * bpp)) = map->content.color;
				ft_printf("I: %d X: %d J: %d Y: %d \n", i, map->content.y, j, map->content.x);
				map = map->next;
			}
			// ft_printf("I: %d X: %d J: %d Y: %d \n", i, map->content.x, j, map->content.y);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(mlx, mlx_wnd, img, WIDTH / 2 - tmp->content.x / 2, HEIGHT / 2 - tmp->content.y / 2);
	mlx_hook(mlx_wnd, 2, 0, key_press, mlx);
	mlx_loop(mlx);

	// printf("%s\n", ft_strchr("12,0xFF00FF", ',') + 1);
	return (0);
}
