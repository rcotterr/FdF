/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/26 15:53:50 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/27 13:49:37 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t i;

	if (n == 0)
		return (0);
	i = 0;
	while (i < (n - 1))
	{
		if (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
			i++;
		else
			break ;
	}
	return ((int)((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]);
}
