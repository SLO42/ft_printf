/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:20:15 by saolivei          #+#    #+#             */
/*   Updated: 2019/01/07 12:59:18 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	printf("printf:  %i and %s\n",123456789 , "this string");
	ft_printf("ft_printf:  %i and %s\n",123456789 ,"this string");
	write(1, "\n", 1);
}
