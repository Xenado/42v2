/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jocaille <jocaille@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/01 15:44:29 by jocaille          #+#    #+#             */
/*   Updated: 2020/06/01 15:44:29 by jocaille         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_min(int a, int b)
{
    if (a <= b)
        return (a);
    else
        return (b);    
}