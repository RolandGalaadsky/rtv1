/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arr.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iradchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/25 13:48:58 by iradchen          #+#    #+#             */
/*   Updated: 2018/03/25 13:48:59 by iradchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rtv1.h"

double	*get_double_arr(char *str)
{
	int		i;
	double	*arr;

	arr = (double *)ft_memalloc(DOUB_ARR_SIZE);
	check_malloc((void *)arr);
	i = 0;
	if (*str != '{')
		error_file();
	str++;
	while (i < 3)
	{
		arr[i] = ft_atod(str);
		while (*str != ',' && *str != '}' && *str)
			str++;
		if ((*str == '}' && i != 2) || !(*str))
			error_file();
		str++;
		i++;
	}
	str--;
	if (*str != '}')
		error_file();
	return (arr);
}

int		*get_int_arr(char *str)
{
	int		i;
	int		*arr;

	arr = (int *)ft_memalloc(INT_ARR_SIZE);
	check_malloc((void *)arr);
	i = 0;
	if (*str != '{')
		error_file();
	while (i < 3)
	{
		str++;
		arr[i] = ft_atoi(str);
		while (*str != ',' && *str && *str != '}')
			str++;
		i++;
	}
	if (*str != '}')
		error_file();
	return (arr);
}
