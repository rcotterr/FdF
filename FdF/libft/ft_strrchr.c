/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 18:25:10 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/29 17:11:04 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	i;
	char	*out;

	i = 0;
	out = NULL;
	while (s[i])
	{
		if (((unsigned char*)s)[i] == ((unsigned char)c))
			out = &((char*)s)[i];
		i++;
	}
	if (((unsigned char*)s)[i] == ((unsigned char)c))
		out = &((char*)s)[i];
	return (out);
}
