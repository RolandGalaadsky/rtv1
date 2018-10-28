/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_lights.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:58:55 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 13:58:57 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void		new_light(char **info, t_light *light, int inf_len)
{
	if (!ft_strcmp("POINT", info[0]) && inf_len == 4)
	{
		light->type = POINT;
		light->info = get_double_arr(info[2]);
		light->intensity = ft_atod(info[1]);
	}
	else if (!ft_strcmp("AMBIENT", info[0]) && inf_len == 3)
	{
		light->type = AMBIENT;
		light->info = NULL;
		light->intensity = ft_atod(info[1]);
	}
	else
		error_file();
}

void		init_lights(char **info, t_list **lights, int inf_len)
{
	t_light light;

	new_light(info, &light, inf_len);
	ft_lstadd(lights, ft_lstnew(&light, sizeof(t_light)));
}
