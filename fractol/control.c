/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 13:21:00 by erahimi           #+#    #+#             */
/*   Updated: 2019/11/05 21:21:43 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void	control(t_fractol *fractol)
{
	mlx_hook(fractol->win_ptr, 4, 0, mouse_press, fractol);
	mlx_hook(fractol->win_ptr, 2, 0, key_press, fractol);
	mlx_hook(fractol->win_ptr, 6, 0, julia_new, fractol);
}

void	ctl(int key, t_fractol *fractol)
{
	if (key == 69)
		fractol->it_max += 5;
	if (key == 78)
	{
		fractol->it_max -= 5;
		if (fractol->it_max < 4)
			fractol->it_max = 1;
	}
	if (key == 1)
		fractol->julia_mouse = fractol->julia_mouse == 0 ? 1 : 0;
	if (key == 49)
		fractol->palette = fractol->palette + 1 > 8 ? 1 : fractol->palette + 1;
}

int		key_press(int key, t_fractol *fractol)
{
	if (key == 53)
		free_exit(&fractol);
	if (key == 123)
		fractol->o_x += 0.1;
	if (key == 124)
		fractol->o_x -= 0.1;
	if (key == 125)
		fractol->o_y += 0.1;
	if (key == 126)
		fractol->o_y -= 0.1;
	if (key == 1 || key == 49 || key == 78 || key == 69)
		ctl(key, fractol);
	draw(fractol);
	return (0);
}

int		mouse_press(int button, int x, int y, t_fractol *fractol)
{
	if (button == 4)
	{
		fractol->o_x += x / fractol->zoom - (x / (fractol->zoom * 1.3));
		fractol->o_y += y / fractol->zoom - (y / (fractol->zoom * 1.3));
		fractol->zoom *= 1.3;
		fractol->it_max++;
	}
	if (button == 5)
	{
		fractol->o_x += x / fractol->zoom - (x / (fractol->zoom / 1.3));
		fractol->o_y += y / fractol->zoom - (y / (fractol->zoom / 1.3));
		fractol->zoom /= 1.3;
		fractol->it_max--;
		if (fractol->it_max < 4)
			fractol->it_max = 4;
	}
	draw(fractol);
	return (0);
}
