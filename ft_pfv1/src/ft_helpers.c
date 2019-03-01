/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 14:47:20 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/17 19:02:48 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void 	create_space_or_sign(t_printf *prtf)
{
	prtf->args->stats->l = 0;
	if (NOT1(PFLAGSIGN))
		return (LSTADD("+", 1));
	else if (NOT1(PFLAGSPACE))
		return (LSTADD(" ", 1));
}

//or = override #::
//when or = 7, we want to print spaces even if the pad_zeros flag is toggled.
//when or = 2, we want to print 0x for the start of a pointer.
//when or = 1, we want to print zeros even if the pad_zeros flag is not toggled.
//when or = 0, we want to be at the whim of the user... DANGER

void 			create_width(t_printf *prtf, int amount, int or)
{
	char 	*tmp;
	int 	i;

	i = 0;
	tmp = ft_strnew(amount);
	if (or == 2)
	{
		tmp[0] = '0';
		tmp[1] = 'x';
		SPEC == 'X' ? ft_vector_appened((prtf->output), ft_strupper(tmp)) : ft_vector_appened((prtf->output), tmp);
	}
	else if ((NOT1(prtf->args->flags->pad_zeros) && or != 7) || or == 1)
	{
		while (amount--)
			tmp[i++] = '0';
		ft_vector_appened((prtf->output), tmp);
	}
	else
	{
		while (amount--)
			tmp[i++] = ' ';
		ft_vector_appened((prtf->output), tmp); 
	}
	ft_strdel(&tmp);
}

void 			first_width(t_printf *prtf, int amount, int or)
{
	char 	*tmp;
	int 	i;

	i = 0;
	tmp = ft_strnew(amount);
	if ((NOT1(prtf->args->flags->pad_zeros) && or != 7) || or == 1)
	{
		while (amount--)
			tmp[i++] = '0';
		if (prtf->args->stats->l)
			create_space_or_sign((prtf));
		ft_vector_appened((prtf->output), tmp);
	}
	else
	{
		while (amount--)
			tmp[i++] = ' ';
		ft_vector_appened((prtf->output), tmp);
		if (prtf->args->stats->l)
			create_space_or_sign((prtf));
	}
	ft_strdel(&tmp);
}
int 			if_alt(t_printf *prtf, int size)
{
	if (NOT1(prtf->args->flags->alt_form))
	{
		if (SPEC == 'o')
		{
			if (PPRE == 0 && size == 0)
			{
				ft_prtf_add("0", 1, prtf);
				return 0;
			}
			else if (PPRE < size)
			{
				PPRE = size + 1;
				return (PPRE);
			}
		}
	}
	return (1);
}
