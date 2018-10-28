/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   del_matrix.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 14:11:34 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 14:11:35 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	del_matrix(double ***matrix)
{
	double	**to_del;
	int		i;

	i = 0;
	if (!matrix)
		return ;
	to_del = *matrix;
	if (!to_del)
		return ;
	while (i < 3)
	{
		ft_memdel((void **)(to_del + i));
		i++;
	}
	ft_memdel((void **)matrix);
}
