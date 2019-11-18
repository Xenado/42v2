/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:01:10 by jocaille          #+#    #+#             */
/*   Updated: 2019/11/17 11:01:11 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strncat(char *dest, char *src, int n)
{
	int		i;
	int		len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] && i < n)
	{
		dest[len + i] = src[i];
		i++;
	}
	dest[len + i] = '\0';
	return (dest);
}

int		ft_strlen(char *s)
{
	int	len;

	len = 0;
	while (s[len])
		len++;
	return (len);
}

t_lstfd	*ft_findfd(t_lstfd *lst, int fd)
{
	while (lst)
	{
		if (lst->fd == fd)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}

void	ft_add_back_newfd(t_lstfd **lst, int fd)
{
	t_lstfd	*new;
	t_lstfd *tmp;

	tmp = ft_lstlast(*lst);
	new = malloc(sizeof(t_lstfd));
	if (new)
	{
		new->fd = fd;
		new->str = NULL;
		new->next = NULL;
		if (tmp)
			tmp->next = new;
		else
			*lst = new;
	}
}

t_lstfd	*ft_lstlast(t_lstfd *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
