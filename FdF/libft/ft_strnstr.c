/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 10:55:47 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/22 18:50:15 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *lstr, const char *sstr, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	while ((i < len) && (lstr[i] != '\0') && (sstr[j] != '\0'))
	{
		if (lstr[i] == sstr[j])
			j++;
		else
		{
			i -= j;
			j = 0;
		}
		i++;
	}
	if (sstr[j] != '\0')
		return (NULL);
	else
		return ((char*)&lstr[i - j]);
}
