/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <nsar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 14:26:35 by nsar              #+#    #+#             */
/*   Updated: 2022/11/22 16:46:11 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*save;
	t_list	*begin;

	begin = *lst;
	save = *lst;
	if (!lst)
		return ;
	if (*lst == NULL || !del)
		return ;
	while (save)
	{
		del(save->content);
		begin = save;
		save = save->next;
		free(begin);
	}
	*lst = NULL;
}
