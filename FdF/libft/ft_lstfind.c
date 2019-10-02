/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:56:35 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/02 18:21:20 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstfind(t_list *begin, const void *data, size_t data_size)
{
	t_list	*tmp;

	if (!begin || !data)
		return (NULL);
	tmp = begin;
	while (tmp)
	{
		if (data_size == tmp->content_size)
			if (!(ft_memcmp(tmp->content, data, data_size)))
				return (tmp);
		tmp = tmp->next;
	}
	return (NULL);
}
