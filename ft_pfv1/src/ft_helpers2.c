/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 14:30:09 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/17 17:27:50 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_chr_in_str(const char *table, int tab_size, char c)
{
	while (--tab_size >= 0)
	{
		if (table[tab_size] == c)
			return (1);
	}
	return (0);
}

void 	ft_prtf_add(char *str, size_t size, t_printf *prtf)
{
	if (PFLEN && SPEC != 'o' && SPEC != 'x' && SPEC != 'X')
	{
		PFLEN = 0;
		if (NOT1(PFLAGSIGN))
			str[0] == '-' ? 0 : LSTADD("+", 1);
		else if (NOT1(PFLAGSPACE))
			LSTADD(" ", 1);
	}
	LSTADD(str, size);
}

void 	precheck(char *str, size_t size, t_printf *prtf)
{
	int i;

	i = 0;
	if (NOT1(prtf->args->flags->alt_form) && SPEC != 'o' && SPEC != 'u'
		&& SPEC != 'i' && SPEC != 'd')
	{
		if ((SPEC == 'f' || SPEC == 'F'))
		{
			while (*str)
			{ 
				if (*str == '.')
				{
					ft_prtf_add(str, size, prtf);
					return ft_strdel(&str);
				}
				str++;
				i++;
			}
			str = str - i;
			ft_prtf_add(str, size, prtf);
			ft_strdel(&str);
			return LSTADD(".", 1);
		}
	}
	ft_prtf_add(str, size, prtf);
	return ft_strdel(&str);
}

void	spec_hex_helper(t_printf *prtf, char *num)
{
	if ((DIFP = DIFSZ(ft_strlen(num), PPRE)) > 0)
	{
		if ((DIFW = DIFSZ((ft_strlen(num) + DIFP), PWIDTH)) > 0)
	 		create_width((prtf), DIFW, 7);
		create_width((prtf), DIFP, 1);
		prtf->args->flags->alt_form != 1 ? create_width(prtf, 2, 2): 0;
		prtf->args->flags->alt_form = prtf->args->flags->alt_form != 1 ? 1 : 1;
	}
	else if ((DIFW = DIFSZ(ft_strlen(num), PWIDTH)) > 0)
	{
		if (prtf->args->flags->pad_zeros != 1)
		{
			prtf->args->flags->alt_form != 1 ? create_width(prtf, 2, 2): 0;
			prtf->args->flags->alt_form = prtf->args->flags->alt_form != 1 ? 1 : 1;
			create_width((prtf), DIFW, 0);
		}
		else
		{
			create_width(prtf, DIFW, 0);
			prtf->args->flags->alt_form != 1 ? create_width(prtf, 2, 2): 0;
			prtf->args->flags->alt_form = prtf->args->flags->alt_form != 1 ? 1 : 1;
		}
	}
	prtf->args->flags->alt_form != 1 ? create_width(prtf, 2, 2): 0;
	prtf->args->flags->alt_form = prtf->args->flags->alt_form != 1 ? 1 : 1;
	IFHEX(num, ft_strlen(num));
}
