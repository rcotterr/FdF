/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/25 16:54:17 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/02 13:38:45 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst && !src)
		return (NULL);
	if ((unsigned char*)dst < (unsigned char*)src)
		ft_memcpy(dst, src, len);
	else
		while (len > 0)
		{
			((unsigned char*)dst)[len - 1] = ((unsigned char*)src)[len - 1];
			len--;
		}
	return (dst);
}
