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

void	ft_strncpy(char *buf, char *src, int size)
{
	int		i;

	i = 0;
	while (i < size && src[i])
	{
		buf[i] = src[i];
		i++;
	}
}

t_lstfd	ft_newfd()
