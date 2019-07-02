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

// t_value 		curr_dot(t_map *begin_list, int x, int y)
// {
// 	t_value		content;

// 	while (begin_list)
// 	{
// 		if (begin_list->content.x == x && begin_list->content.y == y)
// 			content = begin_list->content;
// 		begin_list = begin_list->next;
// 	}
// 	return (content);
// }

// void	find_dots(char *i_ptr, int i, int j, t_map *map, int h, int w, int bpp, t_map *begin_list)
// {
// 	int new_i;
// 	int new_j;
// 	int tmp_i;
// 	int tmp_j;
// 	double new_height_1;
// 	double new_height_2;
// 	double add;
// 	double cur_h;
// 	int new_col;
// 	int col;
// 	float count;
// 	t_value content[2];
// 	t_map  *end;

// 	count = 0;
// 	tmp_j = j;
// 	tmp_i = i;
// 	new_i = i + 50;
// 	new_j = j + 50;
// 	end = getLast(map);
// 	content[0] = curr_dot(begin_list, new_i, j);
// 	content[1] = curr_dot(begin_list, i, new_j);
// 	new_height_2 = content[1].height;
// 	new_height_1 = content[0].height;
// 	add = map->content.height;
// 	cur_h = map->content.height;
// 	new_col = map->content.color;
// 	col = map->content.color;
// 	if (j < end->content.y)
// 	{
// 		while (j <= new_j)
// 		{
// 			col = (int)(map->content.color * (1 - count / 50) + (count / 50) * content[1].color);
// 			*(int *)(i_ptr + (((j + (int)add)  + i * WIDTH) * bpp)) = col;
// 			if (add > new_height_2)
// 				add -= cur_h / 50;
// 			if (add < new_height_2)
// 				add += new_height_2 / 50;
// 			count++;
// 			j++;
// 		}
// 	}
// 	j = tmp_j;
// 	count = 0;
// 	add = map->content.height;
// 	cur_h = map->content.height;
// 	map->content.color = new_col;
// 	col = new_col;
// 	if (i < end->content.x)
// 	{
// 		while (i <= new_i)
// 		{
// 			col = (int)(map->content.color * (1 - count / 50) + (count / 50) * content[0].color);
// 			*(int *)(i_ptr + (((j + (int)add)  + i * WIDTH) * bpp)) = col;
// 			if (add > new_height_1)
// 				add -= cur_h / 50;
// 			if (add < new_height_1)
// 				add += new_height_1 / 50;
// 			count++;
// 			i++;
// 		}
// 	}
// }

// int		main(int argc, char **argv)
// {
// 	void	*mlx;
// 	void	*mlx_wnd;
// 	void	*img;

// 	int 	bpp;
// 	int 	sz;
// 	int 	endian;
// 	char	*i_ptr;
// 	char	*line;
// 	int 	fd;
// 	int     i;
// 	int j;
// 	t_map	*map;
// 	t_map 	*tmp;
// 	t_map 	*begin_list;

// 	i = 0;
// 	fd = open(argv[1], O_RDONLY);
// 	map = NULL;
// 	while (get_next_line(fd, &line) == 1)
// 	{
// 		lst_add(&map, read_map(line, i));
// 		i++;
// 	}
// 	tmp = getLast(map);
// 	begin_list = map;
// 	mlx = mlx_init();
// 	mlx_wnd = mlx_new_window(mlx, WIDTH, HEIGHT, "FdF");
// 	img = mlx_new_image(mlx, WIDTH, HEIGHT);
// 	i_ptr = mlx_get_data_addr(img, &bpp, &sz, &endian);
// 	bpp /= 8;
// 	i = 0;
// 	while (i <= tmp->content.x)
// 	{
// 		j = 0;
// 		while (j <= tmp->content.y)
// 		{
// 			find_dots(i_ptr, i, j, map, tmp->content.x, tmp->content.y, bpp, begin_list);
// 			map = map->next;
// 			j+=50;
// 		}
// 		i+=50;
// 	}
// 	mlx_put_image_to_window(mlx, mlx_wnd, img, WIDTH / 2 - tmp->content.x / 2, HEIGHT / 2 - tmp->content.y / 2);
// 	mlx_hook(mlx_wnd, 2, 0, key_press, mlx);
// 	mlx_loop(mlx);
// 	return (0);
// }

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
	mlx_put_image_to_window(fdf.mlx, fdf.mlx_wnd, fdf.img, WIDTH / 2 - end->content.x / 2, HEIGHT / 2 - end->content.y / 2);
	mlx_hook(fdf.mlx_wnd, 2, 0, key_press, fdf.mlx);
	mlx_loop(fdf.mlx);
	return (0);
}