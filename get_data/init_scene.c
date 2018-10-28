/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:04:14 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:04:15 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"
#define OBJECT "OBJECT"
#define CAM "CAM"
#define LIGHT "LIGHT"
#define SHADOW "SHADOW"

void	del_info(char ***info)
{
	char	**param;
	char	**next;

	param = *info;
	while (*param)
	{
		next = param + 1;
		ft_strdel(param);
		param = next;
	}
	ft_memdel((void **)info);
}

int		info_len(char **info)
{
	int len;

	len = 0;
	while (info[len])
		len++;
	return (len);
}

void	add_to_scene(char **info, int inf_len, t_scene *scene)
{
	if (inf_len == 0)
		error_file();
	if (!ft_strcmp(info[0], OBJECT) && inf_len <= 8)
		init_objects(info + 1, &scene->objects, inf_len);
	else if (!ft_strcmp(info[0], CAM) && inf_len == 3 && !(scene->cam))
		init_cam(info + 1, &scene->cam);
	else if (!ft_strcmp(info[0], LIGHT) && inf_len <= 4)
		init_lights(info + 1, &scene->lightes, inf_len);
	else if (!ft_strcmp(info[0], SHADOW) && inf_len == 1)
		scene->shadow = !(scene->shadow);
	else
		error_file();
}

void	init_scene(t_scene *scene)
{
	int		fd;
	char	*line;
	char	**info;
	int		err;
	int		inf_len;

	fd = open(scene->name, O_RDONLY);
	scene->shadow = 0;
	while ((err = get_next_line(fd, &line)) > 0)
	{
		info = ft_strsplit(line, ' ');
		ft_strdel(&line);
		inf_len = info_len(info);
		add_to_scene(info, inf_len, scene);
		del_info(&info);
	}
	if (err < 0)
		error_file();
	ft_strdel(&line);
	close(fd);
}
