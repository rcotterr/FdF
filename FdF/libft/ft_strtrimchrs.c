/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 16:11:36 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/29 10:32:27 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strtrimchrs(char const *s, char *spaces)
{
	size_t	i;
	size_t	z;
	char	*out;

	if (!s)
		return (NULL);
	z = ft_strlen(s);
	while ((z > 0) && ft_strchrcount(spaces, s[z - 1]))
		z--;
	i = 0;
	while ((z > 0) && ft_strchrcount(spaces, s[i]))
	{
		i++;
		z--;
	}
	if (!(out = ft_strnew(z)))
		return (NULL);
	out = ft_strncpy(out, &s[i], z);
	return (out);
}
