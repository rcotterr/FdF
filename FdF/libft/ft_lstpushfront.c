/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushfront.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcclure <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/02 14:25:35 by mmcclure          #+#    #+#             */
/*   Updated: 2018/12/02 18:07:02 by mmcclure         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstpushfront(t_list **begin, void const *cont, size_t cont_size)
{
	t_list	*new;

	if ((new = ft_lstnew(cont, cont_size)))
		ft_lstadd(begin, new);
}
