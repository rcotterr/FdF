/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:46:59 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/28 12:20:36 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	i;
	char	*out;

	if (!s)
		return (0);
	i = ft_strlen(s);
	out = ft_strnew(i);
	if (!out)
		return (0);
	while (i > 0)
	{
		out[i - 1] = f((i - 1), s[i - 1]);
		i--;
	}
	return (out);
}
