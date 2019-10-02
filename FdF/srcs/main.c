/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 16:31:10 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/12 16:55:29 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static void	free_map(t_arr *arr)
{
	int y;

	y = 0;
	while (y < arr->y)
		free(arr->map[y++]);
	free(arr->map);
	free(arr);
}

int			main(int argc, char **argv)
{
	char	*input;
	t_arr	*map;

	map = 0;
	if (argc != 2)
	{
		ft_printf("Usage: %s <valid map>\n", argv[0]);
		return (0);
	}
	ft_printf("Give me a moment, I'm validating your map - %s\n", argv[1]);
	input = fdf_reader(argv[1]);
	if (input[0])
		map = fdf_valid(input);
	else
		write(2, "Invalid map: No data found.\n", 28);
	if (!map)
		return (0);
	ft_printf("Map size: x - %d, y - %d\n", map->x, map->y);
	if (!(map = make_arr(map, input)))
		return (0);
	window(map);
	ft_strdel(&input);
	free_map(map);
	return (1);
}
