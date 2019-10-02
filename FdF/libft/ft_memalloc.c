/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 16:19:23 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/27 17:29:31 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	void	*out;

	out = (void*)malloc(sizeof(void) * size);
	if (!out)
		return ((void*)(0));
	ft_bzero(out, size);
	return (out);
}
