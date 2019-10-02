/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/29 18:01:01 by mmcclure          #+#    #+#             */
/*   Updated: 2018/11/29 20:18:47 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_itoalen(long int n)
{
	int			size;
	long int	nb;

	nb = n;
	size = 1;
	if (nb < 0)
	{
		size++;
		nb *= -1;
	}
	while (nb >= 10)
	{
		size++;
		nb /= 10;
	}
	return (size);
}

char		*ft_itoa(int n)
{
	char		*out;
	long int	nb;
	size_t		i;

	i = ft_itoalen(n);
	if (!(out = ft_strnew(i)))
		return (0);
	out[i--] = '\0';
	nb = n;
	if (nb < 0)
	{
		nb *= -1;
		out[0] = '-';
	}
	while (nb >= 10)
	{
		out[i--] = ((nb % 10) + '0');
		nb /= 10;
	}
	out[i] = ((nb % 10) + '0');
	return (out);
}
