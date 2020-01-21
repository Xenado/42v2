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
	static char		*str = NULL;

	if (!str)
		str = ft_newstr(1);
	if (!str || !line || BUFFER_SIZE < 1 || fd < 0)
		return (-1);
	if (ft_check_eol(str) >= 0)
	{
		str = ft_line(str, line, ft_check_eol(str));
		return (1);
	}
	return (ft_read(fd, &str, line));
}

int		ft_read(int fd, char **str, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int		ret;

	while ((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		*str = ft_join(*str, buf);
		if (ft_check_eol(*str) >= 0)
		{
			*str = ft_line(*str, line, ft_check_eol(*str));
			return (1);
		}
	}
	if (ret < 0)
		return (-1);
	(void)ft_line(*str, line, -1);
	return (0);
}

char	*ft_join(char *s, char *buf)
{
	char	*str;
	int		i;

	i = 0;
	str = malloc(sizeof(char) * (ft_strlen(s) + ft_strlen(buf) + 1));
	if (!str)
		return (NULL);
	str = ft_strcpy(str, s);
	str = ft_strcat(str, buf);
	free(s);
	return (str);
}

int		ft_check_eol(char *s)
{
	int		i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

char	*ft_line(char *s, char **line, int eol)
{
	char	*str;

	if (eol >= 0)
		*line = ft_substr(s, 0, eol);
	if (eol >= 0 && eol < ft_strlen(s))
		str = ft_substr(s, eol + 1, ft_strlen(s) - eol);
	else if (eol >= 0 && eol == ft_strlen(s))
		str = ft_newstr(1);
	else
	{
		*line = ft_substr(s, 0, ft_strlen(s));
		free(s);
		return (NULL);
	}
	free(s);
	if (!*line || !str)
		return (NULL);
	return (str);
}
