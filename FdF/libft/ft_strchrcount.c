/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchrcount.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 09:46:35 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 13:32:28 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strchrcount(const char *str, int c)
{
	int		i;
	int		coun;

	i = 0;
	coun = 0;
	while (str[i] != '\0')
	{
		if (((unsigned char*)str)[i] == ((unsigned char)c))
			coun++;
		i++;
	}
	return (coun);
}
