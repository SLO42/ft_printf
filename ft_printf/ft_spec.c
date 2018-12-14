/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:36:11 by saolivei          #+#    #+#             */
/*   Updated: 2018/12/13 15:56:09 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    spec_percentage(t_printf *prtf, va_list args)
{

}

void    spec_char(t_printf *prtf, va_list args)
{
    if (prtf->args.stats.pf_l != 1)
        ft_vector_nappend(&(prtf.output), (wchar_t)va_args(args, wint_t), 1);
    else
        ft_vector_nappend(&(prtf.output), va_args(args, int), 1);
}

void    spec_string(t_printf *prtf, va_list args)
{
    if (prtf->args.stats.pf_l != 1)
        ft_vector_nappend(&(prtf.output), va_args(args, char*), prtf->args.precision);
    else
        ft_vector_appened(&(prtf.output), va_arg(args, char*));
    return ;
}

void    spec_signed_int(t_printf *prtf, va_list args)
{
    
}