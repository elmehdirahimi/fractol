/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erahimi <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/03 14:30:09 by erahimi           #+#    #+#             */
/*   Updated: 2019/11/05 21:05:35 by erahimi          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		free_exit(t_fractol **fractol)
{
	mlx_clear_window((*fractol)->mlx_ptr, (*fractol)->win_ptr);
	mlx_destroy_image((*fractol)->mlx_ptr, (*fractol)->img_ptr);
	(*fractol)->img_ptr = NULL;
	mlx_destroy_window((*fractol)->mlx_ptr, (*fractol)->win_ptr);
	(*fractol)->win_ptr = NULL;
	(*fractol)->mlx_ptr = NULL;
	free(*fractol);
	exit(0);
	return (0);
}

int		is_fractol(char *argv)
{
	if (ft_strcmp(argv, "mandelbrot") == 0)
		return (1);
	if (ft_strcmp(argv, "julia") == 0)
		return (2);
	if (ft_strcmp(argv, "burningship") == 0)
		return (3);
	return (0);
}

int		main(int argc, char **argv)
{
	t_fractol *fractol;

	if (argc == 2)
	{
		if (!(fractol = (t_fractol *)malloc(sizeof(t_fractol))))
			return (0);
		if ((fractol->fract = is_fractol(argv[1])))
		{
			initialize(fractol, argv[1]);
			control(fractol);
			mlx_loop(fractol->mlx_ptr);
			return (0);
		}
		free(fractol);
	}
	ft_putendl("usage: ./fractol \"mandelbrot\", \"julia\", \"burningship\"");
	return (0);
}
