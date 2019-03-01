/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_unsigned_int_ll.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:57:22 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/17 16:25:13 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	spec_unsigned_int_u_ll(t_printf *prtf, va_list args)
{
	unsigned long long num;

	num = (unsigned long long)va_arg(args, unsigned long long);
	if (PPRE == 0 && (num == 0))
		return;
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(ft_ull_len_base(num, 10), PPRE)) > 0)
			first_width((prtf), DIFP, 1);
		ADDLST(ft_ulltoa_base(num, 10), ft_ull_len_base(num, 10));
		if ((DIFW = DIFSZ(ft_ull_len_base(num, 10) + DIFP, PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else 
	{
		if ((DIFP = DIFSZ(ft_ull_len_base(num, 10), PPRE)) > 0)
		{
			if ((DIFW = DIFSZ(ft_ull_len_base(num, 10) + DIFP, PWIDTH)) > 0)
				first_width((prtf), DIFW, 0);
			first_width((prtf), DIFP, 1);
		}
		else
			if ((DIFW = DIFSZ(ft_ull_len_base(num, 10), PWIDTH)) > 0)
				first_width((prtf), DIFW, 0);
		ADDLST(ft_ulltoa_base(num, 10), ft_ull_len_base(num, 10));
	}
}

void	spec_unsigned_int_o_ll(t_printf *prtf, va_list args)
{
	char	*num;

	num = ft_ulltoa_base((unsigned long long)va_arg(args, unsigned long long), 8);
	if ((IFALT(ft_strlen(num)) == 0) || ((num[0] == '0') && PPRE == 0))
		return;
	PPRE = PPRE == -1 ? 1 : PPRE;
	if (NOT1(prtf->args->flags->left_just))
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
			create_width((prtf), DIFP, 1);
		LSTADD(num, ft_strlen(num));
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
	{
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
		{
			if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
	 			create_width((prtf), DIFW, 0);
			create_width((prtf), DIFP, 1);
		}
		else if ((DIFW = DIFSZ(ft_strlen(num), PWIDTH)) > 0)
			create_width((prtf), DIFW, 0);
		LSTADD(num, ft_strlen(num));
	}
	free(num);
}

void	spec_unsigned_int_x_ll(t_printf *prtf, va_list args)
{
	char	*num;
	
	num = ft_ulltoa_base((unsigned long long)va_arg(args, unsigned long long), 16);
	PPRE = PPRE == -1 ? 1 : PPRE;
	PWIDTH = prtf->args->flags->alt_form != 1 ? PWIDTH - 2: PWIDTH;
	if (PPRE == 0 && (!(num) || num[0] == '0'))
		return;
	prtf->args->flags->alt_form = num[0] == '0' ? 1 : prtf->args->flags->alt_form;
	if (prtf->args->flags->left_just != 1)
	{
		prtf->args->flags->alt_form != 1 ? create_width(prtf, 2, 2): 0;
		if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
			create_width((prtf), DIFP, 1);
		IFHEX(num, ft_strlen(num));
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_hex_helper(prtf, num);
}
