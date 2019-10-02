/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcotter- <rcotter-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/23 15:24:07 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/06 16:58:18 by rcotter-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long long int	out;
	size_t			i;
	int				flag;

	i = 0;
	flag = 1;
	while ((str[i] == ' ') || (str[i] == '\n') || (str[i] == '\f') ||
			(str[i] == '\t') || (str[i] == '\r') || (str[i] == '\v'))
		i++;
	if (str[i] == '-')
		flag = -1;
	if ((str[i] == '-') || (str[i] == '+'))
		i++;
	out = 0;
	while ((str[i] >= '0') && (str[i] <= '9'))
	{
		if (((out * 10) / 10) != out)
			return (((flag) == -1) ? (0) : (-1));
		out = (out * 10) + (str[i] - '0');
		i++;
	}
	return (flag * out);
}
