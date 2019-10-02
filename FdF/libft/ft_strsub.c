/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 13:08:00 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/28 14:20:58 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*out;

	if ((!s) || (!(out = ft_strnew(len))))
		return (NULL);
	out = ft_strncpy(out, &(s[start]), len);
	return (out);
}
