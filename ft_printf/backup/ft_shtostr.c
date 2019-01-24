/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_shtostr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:12:41 by saolivei          #+#    #+#             */
/*   Updated: 2019/01/07 13:48:32 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char    *ft_shtostr(signed int num)
{
    int length;
    long tmp;
    int i;
    char *output;

    tmp = num;
    length = ft_numlen(num);
    output = ft_strnew(length + 1);
    i = length;
    if (num < 0)
    {
        output[0] = '-';
        tmp *= -1;
    }
    while (i != 0)
    {
        output[i--] = tmp % 10;
        tmp /= 10;
    }
    return(output);
}
