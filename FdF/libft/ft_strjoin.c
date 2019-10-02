/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 15:54:39 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/01 20:18:19 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*out;

	if (s1 && s2)
		out = ft_strnew(ft_strlen(s1) + ft_strlen(s2));
	else
		return (NULL);
	if (!out)
		return (NULL);
	out = ft_strcpy(out, s1);
	out = ft_strcat(out, s2);
	return (out);
}
