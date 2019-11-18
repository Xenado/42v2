/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:00:56 by jocaille          #+#    #+#             */
/*   Updated: 2019/11/17 11:00:58 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	static t_lstfd	*lst;
	t_lstfd			*tmp;
	t_lstfd			*prev;
	int				ret;

	if (!(tmp = ft_findfd(lst, fd)))
	{
		ft_add_back_newfd(&lst, fd);
		tmp = ft_findfd(lst, fd);
	}
	if (!(ret = ft_readfd(fd, line, tmp)))
	{
		prev = lst;
		if (prev->fd == tmp->fd && tmp->next)
			lst = lst->next;
		else if (tmp->next)
		{
			while (prev->next->fd != tmp->fd)
				prev = prev->next;
			prev->next = tmp->next;
		}
		free(tmp->str);
		free(tmp);
	}
	return (ret);
}

int		ft_readfd(int fd, char **line, t_lstfd *lst)
{
	char	*str;
	char	buf[BUFFER_SIZE + 1];
	int		ret;
	int		stop;

	stop = 0;
	str = NULL;
	ft_bzero((char *)buf, BUFFER_SIZE + 1);
	if (lst->str)
		str = ft_realloc(lst->str, buf, 0);
	while (!stop && (ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		stop = ft_check_eol(buf, lst);
		str = ft_realloc(str, buf, stop);
		ft_bzero((char *)buf, BUFFER_SIZE + 1);
	}
	*line = str;
	if (stop)
		return (1);
	if (!ret)
		return (0);
	return (-1);
}

char	*ft_realloc(char *s, char *buf, int eol)
{
	char	*str;
	int		len;

	len = ft_strlen(s) + ft_strlen(buf);
	if (eol)
		len = ft_strlen(s) + eol;
	str = malloc(sizeof(char) * (len + 1));
	ft_bzero((char *)str, len);
	ft_strncat(str, s, ft_strlen(s));
	if (eol)
	{
		ft_strncat(str, buf, eol);
	}
	else
		ft_strncat(str, buf, ft_strlen(buf));
	if (s)
		free(s);
	return (str);
}

int		ft_check_eol(char *buf, t_lstfd *lst)
{
	int		i;

	i = 0;
	while (buf[i] && buf[i] != '\n')
		i++;
	if (buf[i] == '\n')
	{
		if (!(lst->str = malloc(sizeof(char) * (ft_strlen(&buf[i]) + 1))))
		{
			lst->str = NULL;
			return (-1);
		}
		ft_bzero((char *)lst->str, ft_strlen(&buf[i]));
		ft_strncat(lst->str, &buf[i], ft_strlen(&buf[i]));
		return (i);
	}
	return (0);
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((unsigned char*)s)[i] = 0;
		i++;
	}
}
