/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <mmcclure@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:17:12 by mmcclure          #+#    #+#             */
/*   Updated: 2019/03/05 13:18:17 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushback(t_list **begin, void const *content, size_t content_size)
{
	t_list	*tmp;

	if (*begin)
	{
		tmp = *begin;
		while (tmp->next)
			tmp = tmp->next;
		tmp->next = ft_lstnew(content, content_size);
	}
	else
		*begin = ft_lstnew(content, content_size);
}
