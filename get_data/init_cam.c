/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:49:57 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 13:49:59 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	del_cam(t_cam **cam)
{
	ft_memdel((void **)&((*cam)->origin));
	del_matrix(&((*cam)->rotate_matrix));
	ft_memdel((void	**)cam);
}

void	init_cam(char **info, t_cam **cam)
{
	t_cam *new_cam;

	new_cam = (t_cam *)ft_memalloc(sizeof(t_cam));
	new_cam->origin = get_double_arr(info[0]);
	new_cam->rotate_matrix = get_rotate_matrix(info[1]);
	*cam = new_cam;
}
