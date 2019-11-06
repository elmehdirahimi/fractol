/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 12:31:26 by erahimi           #+#    #+#             */
/*   Updated: 2019/11/05 21:02:30 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		get_color(int palette)
{
	if (palette == 1)
		return (0xeeff0000);
	else if (palette == 2)
		return (0xee00ff00);
	else if (palette == 3)
		return (0xee0000ff);
	else if (palette == 4)
		return (0xeeff1234);
	else if (palette == 5)
		return (0xbcabcdef);
	else if (palette == 6)
		return (0xaaaabbbb);
	else if (palette == 7)
		return (0x01234567);
	else if (palette == 8)
		return (0xeeffffff);
	return (0x01234567);
}

void	julia_init(t_fractol *fractol)
{
	fractol->it_max = 30;
	fractol->zoom = 250;
	fractol->o_x = -1.25;
	fractol->o_y = -1.25;
	fractol->c_rel = -0.79;
	fractol->c_img = 0.15;
	fractol->julia_mouse = 1;
}

void	init_mandelbrot(t_fractol *fractol)
{
	fractol->it_max = 30;
	fractol->zoom = 250;
	fractol->o_x = -1.7;
	fractol->o_y = -1.3;
}

void	choose(t_fractol *fractol)
{
	if (fractol->fract == 1)
	{
		fractol->funk_ptr = &mandelbrot;
		init_mandelbrot(fractol);
	}
	else
	{
		if (fractol->fract == 2)
		{
			fractol->funk_ptr = &julia;
			julia_init(fractol);
		}
		else
		{
			if (fractol->fract == 3)
			{
				fractol->funk_ptr = &burningship;
				init_mandelbrot(fractol);
			}
		}
	}
}

void	initialize(t_fractol *fractol, char *argv)
{
	fractol->mlx_ptr = mlx_init();
	fractol->win_ptr = mlx_new_window(fractol->mlx_ptr, 600, 600, argv);
	fractol->img_ptr = mlx_new_image(fractol->mlx_ptr, 600, 600);
	fractol->data = (int *)mlx_get_data_addr(fractol->img_ptr, &(fractol->bpp),\
			&(fractol->size_line), &(fractol->endian));
	fractol->julia_mouse = 0;
	fractol->palette = 1;
	choose(fractol);
	draw(fractol);
}
