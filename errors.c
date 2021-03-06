/* ************************************************************************** */
/* ifsdfs                                                                          */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 15:36:52 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 15:36:53 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

void	error(char *message)
{
	ft_putendl(message);
	exit(0);
}

void	error_file(void)
{
	error("FILE ERROR!");
}

void	check_malloc(void *ptr)
{
	if (!ptr)
		error("CANT MALLOC!");
}
