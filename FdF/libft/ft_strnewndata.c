/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnewndata.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 15:10:27 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/30 17:33:21 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnewndata(char const *str, size_t size)
{
	char	*out;

	out = ft_strnew(size);
	return (ft_memcpy(out, str, size));
}
