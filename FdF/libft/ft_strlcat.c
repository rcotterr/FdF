/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:39:03 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/25 13:15:20 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dsize)
{
	size_t d;
	size_t s;
	size_t out;
	size_t i;

	out = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (dsize > d)
		out = s + d;
	else
		out = s + dsize;
	i = 0;
	while ((src[i] != '\0') && ((d + i + 1) < dsize))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (out);
}
