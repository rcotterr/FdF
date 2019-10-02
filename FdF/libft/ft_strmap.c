/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 11:30:15 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/28 12:10:04 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
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
		out[i - 1] = f(s[i - 1]);
		i--;
	}
	return (out);
}
