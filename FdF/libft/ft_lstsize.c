/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 15:29:33 by mmcclure          #+#    #+#             */
/*   Updated: 2019/02/24 17:28:26 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_lstsize(t_list *begin)
{
	size_t	s;
	t_list	*tmp;

	s = 0;
	tmp = begin;
	while (tmp)
	{
		s += tmp->content_size;
		tmp = tmp->next;
	}
	return (s);
}
