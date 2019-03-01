/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_signed_int.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:59:15 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/17 18:41:09 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void spec_signed_helper(t_printf *prtf, char *num)
{
	if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
	{
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			first_width((prtf), DIFW, 0);
		first_width((prtf), DIFP, 1);
	}
	else if ((DIFW = DIFSZ(ft_strlen(num), PWIDTH)) > 0)
			first_width((prtf), DIFW, 0);
	precheck((num), ft_strlen(num), prtf);
}

void spec_signed_int_l(t_printf *prtf, va_list args)
{
	char *num;

	num = ft_lltoa((long)va_arg(args, long));
	if (PPRE == 0 && (!(num) || *num == 0))
		return;
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		precheck((num), ft_strlen(num), prtf);
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_signed_helper(prtf, num);
}

void spec_signed_int_ll(t_printf *prtf, va_list args)
{
	char *num;

	num = ft_lltoa((long long)va_arg(args, long long));
	if (PPRE == 0 && (!(num) || *num == 0))
		return;
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		precheck((num), ft_strlen(num), prtf);
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_signed_helper(prtf, num);
}

void spec_signed_int_int(t_printf *prtf, va_list args)
{
	char *num;

	num = ft_itoa((int)va_arg(args, signed int));
	if (PPRE == 0 && (!(num) || *num == 0))
		return;
	if (num[0] == '-')
	{
		prtf->args->flags->prepend_sign = 1;
		prtf->args->flags->prepend_space = 1;
	}
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		precheck((num), ft_strlen(num), prtf);
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_signed_helper(prtf, num);
}

void spec_signed_int_h(t_printf *prtf, va_list args)
{
	char *num;

	num = ft_itoa((short)va_arg(args, signed int));
	if (PPRE == 0 && (!(num) || *num == 0))
		return;
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		precheck((num), ft_strlen(num), prtf);
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_signed_helper(prtf, num);
}

void spec_signed_int_hh(t_printf *prtf, va_list args)
{
	char *num;

	num = ft_itoa((signed char)va_arg(args, signed int));
	if (PPRE == 0 && (!(num) || *num == 0))
		return;
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		precheck((num), ft_strlen(num), prtf);
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_signed_helper(prtf, num);
}

