/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 11:00:44 by jocaille          #+#    #+#             */
/*   Updated: 2019/11/17 11:00:46 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
#include <stdio.h>
typedef struct	s_lstfd
{
	int				fd;
	char			*str;
	struct s_lstfd	*next;
}				t_lstfd;

int				get_next_line(int fd, char **line);

char			*ft_strncat(char *dest, char *src, int n);
int				ft_strlen(char *s);
t_lstfd			*ft_findfd(t_lstfd *lst, int fd);
void			ft_add_back_newfd(t_lstfd **lst, int fd);
t_lstfd			*ft_lstlast(t_lstfd *lst);
int				ft_readfd(int fd, char **line, t_lstfd *lst);
char			*ft_realloc(char *s, char *buf, int eol);
int				ft_check_eol(char *buf, t_lstfd *lst);
void			ft_bzero(void *s, size_t n);

#endif
