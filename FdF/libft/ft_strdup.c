/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 13:31:22 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/21 17:39:04 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	i;
	size_t	size;
	char	*out;

	size = ft_strlen(s1);
	out = (char*)malloc(sizeof(const char) * (size + 1));
	if (!out)
		return (NULL);
	i = 0;
	while (i < size)
	{
		out[i] = s1[i];
		i++;
	}
	out[size] = '\0';
	return (out);
}
