/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 13:20:15 by saolivei          #+#    #+#             */
/*   Updated: 2018/12/13 15:56:12 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	main()
{
	void *pointer;
	printf("printf: %p and %s\n", pointer, "this string");
	ft_printf("ft_printf: %p and %s", pointer, "this string");
	write(1, "\n", 1);
}
