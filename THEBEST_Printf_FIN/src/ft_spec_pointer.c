/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:06:04 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/24 12:11:37 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	spec_pointer_help2(t_printf *prtf, size_t len)
{
	if (prtf->args->flags->pad_zeros == 1)
	{
		if ((DIFW = DIFSZ((len + 6), PWIDTH)) > 0)
			create_width((prtf), DIFW, 0);
		create_width((prtf), 2, 2);
	}
	else if (prtf->args->flags->pad_zeros != 1)
	{
		create_width((prtf), 2, 2);
		if ((DIFW = DIFSZ((len + 6), PWIDTH)) > 0)
			create_width((prtf), DIFW, 0);
	}
}

static void	spec_pointer_help(t_printf *prtf, char *point, size_t len)
{
	if ((DIFP = DIFSZ((len + 4), PPRE)) > 0)
	{
		if (prtf->args->flags->pad_zeros == 1)
		{
			if ((DIFW = DIFSZ((len + DIFP + 6), PWIDTH)) > 0)
				create_width((prtf), DIFW, 0);
			create_width((prtf), 2, 2);
		}
		else if (prtf->args->flags->pad_zeros != 1)
		{
			create_width((prtf), 2, 2);
			if ((DIFW = DIFSZ((len + DIFP + 6), PWIDTH)) > 0)
				create_width((prtf), DIFW, 0);
		}
		create_width((prtf), DIFP, 1);
	}
	else
		spec_pointer_help2(prtf, len);
	ft_vector_appened((prtf->output), "7ffe");
	LSTADD(point, len);
}

void		spec_pointer(t_printf *prtf, va_list args)
{
	char	*point;
	size_t	len;

	point = ft_strlower(ft_ltoa_base((unsigned int)va_arg(args, void *), 16));
	len = ft_strlen(point);
	if (NOT1(prtf->args->flags->left_just))
	{
		create_width((prtf), 2, 2);
		if ((DIFP = DIFSZ((len + 4), PPRE)) > 0)
			create_width((prtf), DIFP, 1);
		ft_vector_appened((prtf->output), "7ffe");
		LSTADD(point, len);
		DIFP = DIFP <= 0 ? 0 : DIFP;
		if ((DIFW = DIFSZ((len + DIFP + 6), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_pointer_help((prtf), point, len);
	free(point);
}
