/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:26:31 by iradchen          #+#    #+#             */
/*   Updated: 2018/02/23 17:26:33 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define NOTATION1 "CAM POINT ANGLES"
#define NOTATION2 "LIGHT AMBIENT INTENSITY"
#define NOTATION3 "LIGHT POINT CORDINETS INTENSITY"
#define NOTATION4 "OBJECT PLANE COLOR SPECULAR POINT REFLECTION NORMAL"
#define NOTATION5 "OBJECT SPHERE COLOR SPECULAR CENTER REFLECTION RADIUS "
#define NOTATION6 "OBJECT CYLINDER COLOR SPECULAR CENTER REFLECTION DIRECTION RADIUS"
#define NOTATION7 "OBJECT CONE COLOR SPECULAR CENTER DIRECTON REFLECTION ANGLE"

int		my_exit(void *param)
{
	(void)param;
	exit(0);
	return (0);
}

void	instruction(void)
{
	ft_putendl(NOTATION1);
	ft_putendl(NOTATION2);
	ft_putendl(NOTATION3);
	ft_putendl(NOTATION4);
	ft_putendl(NOTATION5);
	ft_putendl(NOTATION6);
	ft_putendl(NOTATION7);
	exit(0);
}

void	init_mlx(t_mlx *mlx, t_img *img, t_scene *scene)
{
	int i;

	i = 0;
	mlx->mlx_ptr = mlx_init();
	mlx->win_ptr = mlx_new_window(mlx->mlx_ptr, WIDTH, HEIGHT, "rtv1");
	img->size = WIDTH * HEIGHT;
	img->ptr = mlx_new_image(mlx->mlx_ptr, WIDTH, HEIGHT);
	img->data = (int *)mlx_get_data_addr(img->ptr, &img->size, \
		&img->size, &img->size);
	mlx->img = img;
	mlx->scene = scene;
	mlx_hook(mlx->win_ptr, 17, 1L << 17, my_exit, (void *)mlx);
	mlx_key_hook(mlx->win_ptr, key_hook, (void *)mlx);
}

int		main(int ac, char **av)
{
	t_mlx			mlx;
	t_img			img;
	t_scene			*scene;

	if (ac != 2)
		instruction();
	scene = (t_scene *)ft_memalloc(sizeof(t_scene));
	check_malloc(scene);
	scene->name = av[1];
	init_scene(scene);
	init_mlx(&mlx, &img, scene);
	draw(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
