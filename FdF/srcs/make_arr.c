/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_arr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 15:41:50 by rcotter-          #+#    #+#             */
/*   Updated: 2019/03/12 16:55:49 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static int		fill_arr(t_arr *arr, int i, char *str)
{
	int k;
	int j;

	k = 0;
	j = 0;
	while (j < arr->x)
	{
		arr->map[i][j] = ft_atoi(&str[k]);
		while (str[k] == ' ' || str[k] == '\n' || str[k] == '\t')
			k++;
		if (str[k] == '-' || str[k] == '+')
			k++;
		while (str[k] >= '0' && str[k] <= '9')
			k++;
		if (str[k] == ',')
			while (str[k] && (str[k] != ' ' && str[k] != '\t'))
				k++;
		j++;
	}
	return (0);
}

static int		find_z(t_arr *arr)
{
	int x;
	int y;

	x = 0;
	y = 0;
	arr->z_min = arr->map[y][x];
	arr->z_max = arr->map[y][x];
	while (y < arr->y)
	{
		while (x < arr->x)
		{
			if (arr->map[y][x] < arr->z_min)
				arr->z_min = arr->map[y][x];
			if (arr->map[y][x] > arr->z_max)
				arr->z_max = arr->map[y][x];
			x++;
		}
		y++;
		x = 0;
	}
	return (0);
}

static t_arr	*free_map(t_arr *arr, int i)
{
	int y;

	y = 0;
	while (y < i)
		free(arr->map[y++]);
	free(arr->map);
	free(arr);
	return (NULL);
}

t_arr			*make_arr(t_arr *arr, char *str)
{
	int i;

	i = 0;
	if (!(arr->map = (int **)malloc(sizeof(int*) * arr->y)))
		return (free_map(arr, 0));
	while (i < arr->y)
	{
		if (!(arr->map[i] = (int *)malloc(sizeof(int) * arr->x)))
			return (free_map(arr, i));
		fill_arr(arr, i, str);
		while (*str != '\n' && *str)
			str++;
		str++;
		i++;
	}
	find_z(arr);
	return (arr);
}
