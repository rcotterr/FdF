/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 13:13:50 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/01 19:45:10 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while ((s1[i] != '\0') && (s2[i] != '\0'))
	{
		if (((unsigned char*)s1)[i] == ((unsigned char*)s2)[i])
			i++;
		else
			break ;
	}
	return ((int)(((unsigned char*)s1)[i] - ((unsigned char*)s2)[i]));
}
