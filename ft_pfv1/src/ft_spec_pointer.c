/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec_pointer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 20:06:04 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/09 15:31:24 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void spec_pointer_help(t_printf *prtf, char *point)
{
	if ((DIFP = DIFSZ((ft_strlen(point) + 4), PPRE)) > 0)
	{
		if ((DIFW = DIFSZ((ft_strlen(point) + DIFP + 6), PWIDTH)) > 0)
			create_width((prtf), DIFW, 0);
		create_width((prtf), 2, 2);
		create_width((prtf), DIFP, 1);
	}
	else
	{
		if ((DIFW = DIFSZ((ft_strlen(point) + 6), PWIDTH)) > 0)
			create_width((prtf), DIFW, 0);
		create_width((prtf), 2, 2);
	}
	ft_vector_appened((prtf->output), "7ffe");
	LSTADD(point, ft_strlen(point));
}

void 		spec_pointer(t_printf *prtf, va_list args)
{
	char *point;

	point = ft_strlower(ft_ltoa_base((unsigned int)va_arg(args, void *), 16));
	if (NOT1(prtf->args->flags->left_just))
	{
		create_width((prtf), 2, 2);
		if ((DIFP = DIFSZ((ft_strlen(point) + 4), PPRE)) > 0)
			create_width((prtf), DIFP, 1);
		ft_vector_appened((prtf->output), "7ffe");
		LSTADD(point, ft_strlen(point));
		DIFP = DIFP <= 0 ? 0 : DIFP;
		if ((DIFW = DIFSZ((ft_strlen(point) + DIFP + 6), PWIDTH)) > 0)
			create_width((prtf), DIFW, 7);
	}
	else
		spec_pointer_help((prtf), point);
	free(point);
}
