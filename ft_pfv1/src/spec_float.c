/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spec_float.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 15:19:25 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/09 19:45:05 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int ft_strlen_nodot(char *str)
{
	int i;
	int flag;

	flag = 0;
	i = 0;
	while (str[i] != 0)
	{
		if (str[i] == '.')
			flag = 1;
		i++;
	}
	return (flag ? i - 1 : i );
}

void spec_float_L(t_printf *prtf, va_list args)
{
	char *num;

	num = ft_ftoa((long double)va_arg(args, long double), prtf);
	PPRE = DIFP;
	if (NOT1(prtf->args->flags->left_just))
	{
		PRECK(num, ft_strlen(num));
		if ((DIFW = DIFSZ(ft_strlen_nodot(num), PWIDTH)) > 0)
			create_width(prtf, DIFW, 7);
	}
	else
	{
		if ((DIFW = DIFSZ(ft_strlen_nodot(num), PWIDTH)) > 0)
			first_width(prtf, DIFW, 0);
		PRECK(num, ft_strlen(num));
	}
}

void spec_float_float(t_printf *prtf, va_list args)
{
	char *num;

	num = ft_ftoa((float)va_arg(args, double), prtf);
	PPRE = DIFP;
	if (NOT1(prtf->args->flags->left_just))
	{
		PRECK(num, ft_strlen(num));
		if ((DIFW = DIFSZ(ft_strlen_nodot(num), PWIDTH)) > 0)
			create_width(prtf, DIFW, 7);
	}
	else
	{
		if ((DIFW = DIFSZ(ft_strlen_nodot(num), PWIDTH)) > 0)
			first_width(prtf, DIFW, 0);
		PRECK(num, ft_strlen(num));
	}
}

void spec_float_l(t_printf *prtf, va_list args)
{
	char *num;

	num = ft_ftoa((double)va_arg(args,double), prtf);
	PPRE = DIFP;
	if (NOT1(prtf->args->flags->left_just))
	{
		PRECK(num, ft_strlen(num));
		if ((DIFW = DIFSZ(ft_strlen_nodot(num), PWIDTH)) > 0)
			create_width(prtf, DIFW, 7);
	}
	else
	{
		if ((DIFW = DIFSZ(ft_strlen_nodot(num), PWIDTH)) > 0)
			first_width(prtf, DIFW, 0);
		PRECK(num, ft_strlen(num));
	}
}
