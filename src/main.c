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

t_value 		curr_dot(t_map *begin_list, int x, int y)
{
	t_value		content;

	while (begin_list)
	{
		if (begin_list->content.x == x && begin_list->content.y == y)
			content = begin_list->content;
		begin_list = begin_list->next;
	}
	return (content);
}

void	find_dots(char *i_ptr, int i, int j, t_map *map, int h, int w, int bpp, t_map *begin_list)
{
	int new_i;
	int new_j;
	int tmp_i;
	int tmp_j;
	int count;
	count = 0;
	t_value content[2];

	tmp_j = j;
	tmp_i = i;
	new_i = i - 50;
	new_j = j - 50;
	// int s = j + (new_j - j) / 2;
	// int d = i + (new_i - i) / 2;
	content[0] = curr_dot(begin_list, new_i, j);
	content[1] = curr_dot(begin_list, i, new_j);
	if (j > 0)
		while (j > new_j + map->content.height)
		{
			if (content[1].color != map->content.color)
			{
				// if (j < s)
				// 	*(int *)(i_ptr + ((j + i * WIDTH) * bpp)) = map->content.color;
				// else
					// *(int *)(i_ptr + ((j + i * WIDTH) * bpp)) = content[1].color;
					*(int *)(i_ptr + ((j + i * WIDTH) * bpp)) = ft_atoi_base("0xFFFFFF", 16);
			}
			else
				*(int *)(i_ptr + (((j + map->content.height)  + (i + map->content.height) * WIDTH) * bpp)) = map->content.color;
			j--;
			if (map->content.height > 0)
				i--;
		}
	j = tmp_j;
	i = tmp_i;
	if (i > 0)
		while (i > new_i + map->content.height)
		{
			if (content[0].color != map->content.color)
			{
				// if (i < d)
				// 	*(int *)(i_ptr + ((j + i * WIDTH) * bpp)) = map->content.color;
				// else
					// *(int *)(i_ptr + ((j + i * WIDTH) * bpp)) = content[0].color;
					*(int *)(i_ptr + ((j + i * WIDTH) * bpp)) = ft_atoi_base("0xFFFFFF", 16);
			}
			else
				*(int *)(i_ptr + (((j + map->content.height)  + (i + map->content.height) * WIDTH) * bpp)) = map->content.color;
			i--;
			if (map->content.height > 0)
				j--;
		}
	// while (count < map->content.height)
	// {
	// 	*(int *)(i_ptr + ((j  + i * WIDTH) * bpp)) = map->content.color;
	// 	i++;
	// 	j++;
	// 	count++;
	// }
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
	t_map 	*begin_list;

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
	begin_list = map;
	mlx = mlx_init();
	mlx_wnd = mlx_new_window(mlx, WIDTH, HEIGHT, "first fdf");
	img = mlx_new_image(mlx, WIDTH, HEIGHT);
	i_ptr = mlx_get_data_addr(img, &bpp, &sz, &endian);
	bpp /= 8;
	i = 0;
	while (i <= tmp->content.x)
	{
		j = 0;
		while (j <= tmp->content.y)
		{
			find_dots(i_ptr, i, j, map, tmp->content.x, tmp->content.y, bpp, begin_list);
			map = map->next;
			j+=50;
		}
		i+=50;
	}
	// printf("%d ==== \n", ft_atoi_base("0xFF0000", 16));
	mlx_put_image_to_window(mlx, mlx_wnd, img, WIDTH / 2 - tmp->content.x / 2, HEIGHT / 2 - tmp->content.y / 2);
	mlx_hook(mlx_wnd, 2, 0, key_press, mlx);
	mlx_loop(mlx);

	// printf("%d\n", ft_atoi_base("0xFF0000", 16));
	return (0);
}
