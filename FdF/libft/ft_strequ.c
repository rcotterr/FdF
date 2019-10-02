/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:21:26 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/01 19:37:34 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	if (!s1 || !s2)
		return ((s1 == s2) ? 1 : 0);
	if (ft_strcmp(s1, s2) != 0)
		return (0);
	else
		return (1);
}
