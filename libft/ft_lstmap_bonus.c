/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nsar <nsar@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 22:28:24 by nsar              #+#    #+#             */
/*   Updated: 2022/11/22 16:46:11 by nsar             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	**r;
	t_list	*current;
	t_list	*new;

	if (!lst)
		return (NULL);
	if (!(r = (t_list**)malloc(ft_lstsize(lst) * sizeof(*r))))
		return (NULL);
	*r = NULL;
	current = lst;
	while (current)
	{
		if (!(new = ft_lstnew(f(current->content))))
		{
			ft_lstclear(r, del);
			free(r);
			return (NULL);
		}
		ft_lstadd_back(r, new);
		current = current->next;
	}
	return (*r);
}
