/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_bindings.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykliek <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/17 09:27:43 by ykliek            #+#    #+#             */
/*   Updated: 2019/07/17 09:27:45 by ykliek           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color(int	keycode, t_mlx *fdf)
{	
	fdf->up = 0;
	if (keycode >= 83 && keycode <= 92)
	{
		change_color_btype(keycode, fdf);
		fdf->lamp = 1;
		image(fdf);
	}
	if (keycode == 82)
	{
		fdf->lamp = 1;
		if (fdf->color_t == 0)
			fdf->color_t = 1;
		else if (fdf->color_t == 1)
			fdf->color_t = 2;
		else if (fdf->color_t == 2)
			fdf->color_t = 0;
	}
	return (0);
}

int		spin(int keycode, t_mlx	*fdf)
{
	if (keycode == 13 || keycode == 0 || keycode == 1 || keycode == 2)
	{
		fdf->lamp = 1;
		if (keycode == 13 || keycode == 1)
		{
			fdf->spin_mode = 1;
			fdf->alfa = (keycode == 13) ? fdf->alfa + 0.1 : fdf->alfa - 0.1;
		}
		if (keycode == 0 || keycode == 2)
		{
			fdf->spin_mode = 0;
			fdf->alfa = (keycode == 0) ? fdf->alfa + 0.1 : fdf->alfa - 0.1;
		}
		fdf->up = 0;
		image(fdf);
	}
	color(keycode, fdf);
	return (0);
}

int		key_press(int keycode, t_mlx *fdf)
{
	fdf->up = 0;
	if (keycode == 49 || keycode == 53)
		exit(EXIT_SUCCESS);
	if (keycode == 123 || keycode == 124 || keycode == 125 || keycode == 126)
	{
		fdf->lamp = 1;
		move(fdf, keycode);
		image(fdf);
	}
	if (keycode == 12)
	{
		fdf->lamp = 1;
		fdf->izo_mod = (fdf->izo_mod == 0) ? 1 : 0;
		fdf->cam->start_x = 0;
		fdf->cam->start_y = 0;
		image(fdf);
	}
	if (keycode == 69 || keycode == 78)
	{
		fdf->lamp = 0;
		ret_scale(fdf);
		zoom(keycode, fdf);
		image(fdf);
	}
	spin(keycode, fdf);
	return (0);
}

int		mouse_press(int button, int x, int y, t_mlx *fdf)
{
	fdf->lamp = 1;
	if (button == 4)
	{
		fdf->up = 1;
		image(fdf);
	}
	else if (button == 5)
	{
		fdf->up = -1;
		image(fdf);
	}
	return (0);
}
