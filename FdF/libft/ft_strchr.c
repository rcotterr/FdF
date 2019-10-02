/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 16:20:56 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/29 17:10:14 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	while (s[i])
	{
		if (((unsigned char*)s)[i] == ((unsigned char)c))
			return ((char*)&(s[i]));
		i++;
	}
	if (((unsigned char)c) == '\0')
		return ((char*)&(s[i]));
	return (NULL);
}
