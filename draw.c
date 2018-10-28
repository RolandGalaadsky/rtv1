/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:35:37 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 15:35:39 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define WIDTH_2 300
#define HEIGHT_2 300
#define V_H 1
#define V_W 1
#define DIST 1
#define RAYSTART 1
#define RAYEND	DBL_MAX

void	img_put_pixel(t_img *img, int x, int y, int color)
{
	x = x + WIDTH_2;
	y = -y + HEIGHT_2;
	img->data[y * WIDTH + x] = color;
}

void	window_to_viewport(double *point, int x, int y)
{
	point[0] = (x * V_W) / (double)WIDTH;
	point[1] = (y * V_H) / (double)HEIGHT;
	point[2] = DIST;
}

void	fill_img(t_img *img, t_scene *scene)
{
	int		x;
	int		y;
	t_cam	*cam;
	double	point[3];
	double	**trans;

	x = -WIDTH_2;
	cam = scene->cam;
	trans = trans_matrix(cam->rotate_matrix);
	while (x < WIDTH_2)
	{
		y = HEIGHT_2;
		while (y > -HEIGHT_2)
		{
			window_to_viewport(point, x, y);
			rotate(point, trans);
			img_put_pixel(img, x, y, trace_ray(point, scene->cam->origin, scene, RAYSTART, RAYEND, 3));
			y--;
		}
		x++;
	}
	del_matrix(&trans);
}

void	draw(t_mlx *mlx)
{
	fill_img(mlx->img, mlx->scene);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->win_ptr, (mlx->img)->ptr, 0, 0);
}
