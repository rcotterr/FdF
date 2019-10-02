/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/01 17:53:52 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/02 15:22:57 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void		del_cont(void *data, size_t data_size)
{
	if (data)
		ft_memdel(&data);
	data_size = 0;
}

t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*begin;
	t_list	*tmp;

	if (!(lst) || !(f))
		return (NULL);
	if (!(tmp = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		return (NULL);
	begin = tmp;
	while (lst->next)
	{
		lst = lst->next;
		if (!(tmp->next = ft_lstnew(f(lst)->content, f(lst)->content_size)))
		{
			ft_lstdel(&begin, &del_cont);
			return (NULL);
		}
		tmp = tmp->next;
	}
	return (begin);
}
