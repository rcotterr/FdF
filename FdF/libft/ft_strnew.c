/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/27 18:12:31 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/02 15:17:16 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char	*out;

	if ((size + 1) == 0)
		return (NULL);
	out = (char*)malloc(sizeof(char) * (size + 1));
	if (!out)
		return (NULL);
	ft_bzero(out, size + 1);
	return (out);
}
