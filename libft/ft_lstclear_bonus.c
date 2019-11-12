/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 14:58:14 by jocaille          #+#    #+#             */
/*   Updated: 2019/11/12 14:58:16 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_bonus.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next;

	if (lst)
	{
		tmp = *lst;
		while (tmp)
		{
			if (tmp->content)
				(*del)(tmp->content);
			next = tmp->next;
			free(tmp);
			tmp = next;
		}
	}
	lst = NULL;
}
