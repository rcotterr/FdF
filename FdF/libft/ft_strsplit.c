/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 09:40:54 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/01 17:48:32 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	char	*ch;
	char	*str;

	if ((!s) || (!c))
		return (NULL);
	if (!(ch = ft_strnew(1)))
		return (NULL);
	ch[0] = c;
	if (!(str = ft_strnewndata(s, ft_strlen(s))))
		return (NULL);
	return (ft_strsplitchrs(str, ch));
}
