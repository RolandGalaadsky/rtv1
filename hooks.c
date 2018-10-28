/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:32:49 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 15:32:51 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define PLUS 69
#define ESC 53

void	del_objects(t_list **objects)
{
	t_list		*curr;
	t_list		*next;
	t_object	*object;

	curr = *objects;
	if (curr)
		next = curr->next;
	while (curr)
	{
		object = (t_object *)curr->content;
		ft_memdel((void **)&object->c);
		ft_memdel((void **)&object->dir);
		ft_memdel((void **)&object);
		ft_memdel((void **)&curr);
		curr = next;
		if (curr)
			next = curr->next;
	}
	*objects = NULL;
}

void	del_lights(t_list **lights)
{
	t_list		*curr;
	t_list		*next;
	t_light		*light;

	curr = *lights;
	if (curr)
		next = curr->next;
	while (curr)
	{
		light = (t_light *)curr->content;
		if (light->type == POINT)
			ft_memdel((void **)&light->info);
		ft_memdel((void **)&light);
		ft_memdel((void **)&curr);
		curr = next;
		if (curr)
			next = curr->next;
	}
	*lights = NULL;
}

int		redraw_hook(t_mlx *mlx)
{
	t_scene *scene;

	scene = mlx->scene;
	del_objects(&scene->objects);
	del_lights(&scene->lightes);
	del_cam(&scene->cam);
	init_scene(scene);
	draw(mlx);
	return (0);
}

int		key_hook(int key, void *param)
{
	if (key == 65451)
		redraw_hook((t_mlx *)param);
	if (key == ESC)
		exit(0);
	return (0);
}
