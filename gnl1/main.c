/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/18 18:25:22 by jocaille          #+#    #+#             */
/*   Updated: 2019/11/18 18:25:25 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>

int		main(int ac, char **av)
{
	int		ret;
	char	*str;
	int		i = 0;

	(void)ac;
	ret = open(av[1], O_RDONLY);
	while ((i = get_next_line(ret, &str)) > 0)
	{
		printf("%d | %s\n", i, str);
	}
}
