/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/30 18:12:42 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/01 17:16:02 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*list;
	t_list	*tmp;

	if (!alst || !del)
		return ;
	list = *alst;
	while (list)
	{
		tmp = list;
		ft_lstdelone(&list, del);
		list = tmp->next;
	}
	*alst = NULL;
}
