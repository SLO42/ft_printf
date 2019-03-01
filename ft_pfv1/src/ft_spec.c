/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:36:11 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/17 18:08:45 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void spec_percentage(t_printf *prtf)
{
	if (prtf->args->width - 1 > 0)
	{
		if (NOT1(prtf->args->flags->left_just))
		{
			ft_vector_appened((prtf->output), "%");
			create_width(prtf, prtf->args->width - 1, 7);
		}
		else
		{
			create_width(prtf, prtf->args->width - 1, 0);
			ft_vector_appened((prtf->output), "%");
		}
	}
	else
		ft_vector_appened((prtf->output), "%");
}

void    ft_vector_appened_null(t_vector *vector)
{
    size_t nd_len;

    nd_len = 1;
    if (vector->cap < vector->len + nd_len)
        ft_vector_resize(vector, vector->len + nd_len);
    ft_memcpy(vector->data + vector->len, "\0", nd_len);
    vector->len += nd_len;
}

void spec_char(t_printf *prtf, va_list args)
{
	int 	dif;
	char 	*c;

	if (!(c = ft_strnew(2)))
		ft_exit(-1, prtf);
	(c[0] = (unsigned char)va_arg(args, unsigned int)) < 0 ? c[0] *= -1 : 0 ;
	dif = DIFSZ(1, PWIDTH);
	if (dif)
	{
		if (NOT1(prtf->args->flags->left_just))
		{
			c[0] == '\0' ? ft_vector_appened_null((prtf->output)) : ft_vector_appened((prtf->output), c);
			create_width((prtf), dif, 7);
		}
		else
		{
			create_width((prtf), dif, 0);
			c[0] == '\0' ? ft_vector_appened_null((prtf->output)) : ft_vector_appened((prtf->output), c);
		}
	}
	else
		c[0] == '\0' ? ft_vector_appened_null((prtf->output)) : ft_vector_appened((prtf->output), c);
	if (c)
		free(c);
}

void spec_string(t_printf *prtf, va_list args)
{
	char 	*tmp;
	int 	dif;

	tmp = ft_strdup((char *)va_arg(args, char *));
	if (PPRE != -1 && (int)ft_strlen(tmp) > PPRE)
		tmp = ft_strsub(tmp, 0, PPRE);
	if ((dif = DIFSZ(ft_strlen(tmp), PWIDTH)) > 0)
	{
		if (NOT1(prtf->args->flags->left_just))
		{
			ft_vector_appened((prtf->output), tmp);
			create_width((prtf), dif, 7);
		}
		else
		{
			create_width((prtf), dif, 0);
			ft_vector_appened((prtf->output), tmp);
		}
	}
	else
 		ft_vector_appened((prtf->output), tmp);
	if (tmp)
		free(tmp);
}
void spec_float(t_printf *prtf, va_list args)
{
	PPRE = (PPRE == -1) ? 6 : PPRE;
	if (NOT1(prtf->args->stats->pf_L))
		spec_float_L(prtf, args);
	else if (NOT1(prtf->args->stats->pf_l))
		spec_float_l(prtf, args);
	else
		spec_float_float(prtf, args);
}