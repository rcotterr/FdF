/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 17:09:41 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/11 17:27:47 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../fdf.h"

static t_arr	*fdf_close_rep(const char *str, t_arr **arr)
{
	write(2, str, ft_strlen(str));
	free(*arr);
	*arr = NULL;
	return (NULL);
}

static t_arr	*fdf_arr_init(char **str)
{
	t_arr	*arr;

	if (!(arr = (t_arr*)malloc(sizeof(t_arr))))
		return ((t_arr*)0);
	arr->x = 0;
	while ((**str) && (**str != '\n'))
	{
		while (**str == ' ' || **str == '\t')
			*str += 1;
		if ((**str) && !ft_strchr("0123456789,-+", **str))
			return (fdf_close_rep("Invalid map: bad character.\n", &arr));
		while ((**str >= '0' && **str <= '9') || **str == '+' || **str == '-')
			*str += 1;
		if ((**str == ',') && (*str += 1))
			while ((**str) && ft_strchr("x0123456789ABCDEFabcdef", **str))
				*str += 1;
		arr->x++;
		while (**str == ' ' || **str == '\t')
			*str += 1;
	}
	if (**str == '\n')
		*str += 1;
	arr->y = 1;
	return (arr);
}

static t_arr	*fdf_val_size_char(char **str, t_arr *arr)
{
	int		len;

	len = 0;
	while (**str)
	{
		while (**str == ' ' || **str == '\t')
			*str += 1;
		if ((**str) && !ft_strchr("0123456789,-+", **str))
			return (fdf_close_rep("Invalid map: bad character.\n", &arr));
		while ((**str >= '0' && **str <= '9') || **str == '+' || **str == '-')
			*str += 1;
		if ((**str == ',') && (*str += 1))
			while (ft_strchr("x0123456789ABCDEFabcdef", **str))
				*str += 1;
		len++;
		while (**str == ' ' || **str == '\t')
			*str += 1;
		if ((**str == '\n') && (*str += 1) && (arr->y++))
		{
			if (len != arr->x)
				return (fdf_close_rep("Invalid map: Wrong line len.\n", &arr));
			len = 0;
		}
	}
	return (arr);
}

t_arr			*fdf_valid(char *str)
{
	t_arr	*arr;

	if (!(arr = fdf_arr_init(&str)))
		return (NULL);
	if (!fdf_val_size_char(&str, arr))
		return (NULL);
	return (arr);
}
