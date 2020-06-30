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

int		get_next_line(int fd, char **line);
char	*ft_join(char *s, char *buf);
int		ft_check_eol(char *s);
char	*ft_line(char *s, char **line, int eol);
int		ft_read(int fd, char **str, char **line);

int		ft_strlen(const char *str);
char	*ft_strcpy(char *dst, const char *src);
char	*ft_strcat(char *s1, const char *s2);
char	*ft_newstr(size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);

#endif
