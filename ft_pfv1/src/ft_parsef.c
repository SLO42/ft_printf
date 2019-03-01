/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:25:33 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/17 18:08:38 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void 		parse_flags(t_printf *prtf)
{
	static char 	flags[5] = "-+ #0";
	char 			*tmp;

	while (++prtf->fmt != 0)
	{
		if (CMP(prtf->args->flags->f, 1))
			prtf->args->flags->f = 0;
		tmp = ft_strchr(flags, *prtf->fmt);
		if ((tmp == NULL) || (ft_chr_in_str("-+ #0", 5, *tmp)) == 0)
			return;
		else if (CMP(*tmp, flags[0]))
			prtf->args->flags->left_just++;
		else if (CMP(*tmp, flags[1]))
			prtf->args->flags->prepend_sign++;
		else if (CMP(*tmp, flags[2]))
			prtf->args->flags->prepend_space++;
		else if (CMP(*tmp, flags[3]))
			prtf->args->flags->alt_form++;
		else if (CMP(*tmp, flags[4]))
			prtf->args->flags->pad_zeros++;
	}
	if (tmp)
		free(tmp);
}

static void 		printf_get_length(t_printf *prtf)
{
	static char 	flags[3] = "lLh";
	char			*tmp;

	while (prtf->fmt != 0)
	{
		tmp = ft_strchr(flags, *prtf->fmt);
		if (tmp == NULL || ft_chr_in_str("lLh", 3, *prtf->fmt) == 0)
		{
			while (ft_chr_in_str("%cspdiouxXfF", 12, *prtf->fmt) == 0)
				prtf->fmt++;
			return;
		}
		else if (CMP(*tmp, flags[0]))
		{
			tmp++;
			if (CMP(*tmp, flags[0]))
				prtf->args->stats->pf_ll += 1;
			else
				prtf->args->stats->pf_l += 1;
			prtf->fmt += NOT1(prtf->args->stats->pf_ll) ? 2 : 1;

		}
		else if (CMP(*tmp, flags[2]))
		{
			tmp++;
			if (CMP(*tmp, flags[2]))
				prtf->args->stats->pf_hh += 1;
			else
				prtf->args->stats->pf_h += 1;
			prtf->fmt += NOT1(prtf->args->stats->pf_hh) ? 2 : 1;
		}
		else if (CMP(*tmp, flags[1]))
		{
			prtf->args->stats->pf_L += 1;
			prtf->fmt++;
		}
		else
			prtf->fmt++;
	}
}

static void 		printf_get_widthcision(t_printf *prtf)
{
	while (*prtf->fmt != 0)
	{
		if (ft_isdigit(*prtf->fmt))
		{
			prtf->args->width = ft_atoi(prtf->fmt);
			prtf->fmt += ft_numlen(prtf->args->width);
		}
		if (CMP(*prtf->fmt, '.'))
		{
			prtf->args->pre = prtf->fmt++ ? 0 : 0;
			if (ft_isdigit(*prtf->fmt))
			{
				prtf->args->pre = ft_atoi(prtf->fmt);
				prtf->fmt += ft_numlen(prtf->args->pre);
			}
			else if (*prtf->fmt == '-')
				while ((ft_isdigit(*prtf->fmt)))
					prtf->fmt++;
		}
		prtf->args->pre = prtf->args->pre < 0 ? -1 : prtf->args->pre;
		return;
	}
}

void 				clean_parse(t_printf *prtf)
{
	prtf->args->width = 0;
	prtf->args->pre = -1;
	prtf->args->spec = 0;
	prtf->args->flags->f = 1;
	prtf->args->flags->left_just = 1;
	prtf->args->flags->prepend_sign = 1;
	prtf->args->flags->prepend_space = 1;
	prtf->args->flags->alt_form = 1;
	prtf->args->flags->pad_zeros = 1;
	prtf->args->stats->l = 1;
	prtf->args->stats->pf_hh = 1;
	prtf->args->stats->pf_h = 1;
	prtf->args->stats->pf_l = 1;
	prtf->args->stats->pf_ll = 1;
	prtf->args->stats->pf_L = 1;
	DIFW = 0;
	DIFP = 0;
}

void 				parse_f(va_list args, t_printf *prtf)
{
	clean_parse(prtf);
	parse_flags(prtf);
	printf_get_widthcision((prtf));
	printf_get_length((prtf));
	printf_get_spec((prtf), args);
	//parse width /[.]precision
	// size
	// type
}