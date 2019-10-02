/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 12:23:07 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/28 12:54:49 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strnequ(char const *s1, char const *s2, size_t n)
{
	if ((!s1) || (!s2))
		return (0);
	else if (ft_strncmp(s1, s2, n) == 0)
		return (1);
	else
		return (0);
}
