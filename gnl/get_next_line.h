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
# include <sys =/uio.h>
# include <unistd.h>

# define BUFFER_SIZE

typedef struct	s_lstfd
{
	int				fd;
	char			buf[BUFFER_SIZE];
	struct s_lstfd	*next;
}				t_lstfd;

int				get_next_line(int fd, char **line);
void			ft_strncpy(char *buf, char *src, int size);

#endif
