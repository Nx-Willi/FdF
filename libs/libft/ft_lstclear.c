/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wdebotte <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 14:23:54 by wdebotte          #+#    #+#             */
/*   Updated: 2021/12/01 17:39:45 by wdebotte         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*buffer_lst;

	while (*lst != NULL)
	{
		buffer_lst = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = buffer_lst;
	}
}
