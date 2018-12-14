/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:25:33 by saolivei          #+#    #+#             */
/*   Updated: 2018/12/13 15:56:11 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 

void    parse_flags(va_list args, t_printf *prtf)
{
    static char flags[] = "-+ #0";
    char        *tmp;
    char        fc;

    while (++prtf->fmt != 0)
    {
        if (!(tmp = ft_strchr(flags, *prtf->fmt)))
            return ;
        if (CMP(*tmp, flags[0]))
            prtf->args.flags.left_just++;
        if (CMP(*tmp, flags[1]))
            prtf->args.flags.prepend_sign++;
        if (CMP(*tmp, flags[2]))
            prtf->args.flags.prepend_space++;
        if (CMP(*tmp, flags[3]))
            prtf->args.flags.alt_form++;
        if (CMP(*tmp, flags[4]))
            prtf->args.flags.pad_zeros++;
    }
}

void    printf_get_length(t_printf *prtf, va_list args)
{
    while (++prtf->fmt != 0)
    {
        if (*prtf->fmt == 'l')
        {
            if (prtf->fmt[1] == 'l')
            {
                prtf->fmt++;
                prtf->args.stats.pf_ll += 1;
            }
            else
                prtf->args.stats.pf_l += 1;
        }
        else if (*prtf->fmt == 'h')
        {
            if (prtf->fmt[1] == 'h')
            {
                prtf->fmt++;
                prtf->args.stats.pf_hh += 1;
            }
            else
                prtf->args.stats.pf_h += 1;
        }
        else if(*prtf->fmt == 'z')
            prtf->args.stats.pf_z += 1;
    }
}

void    printf_get_widthcision(t_printf *prtf, va_list args)
{
    while (*prtf->fmt != 0)
    {
        if (ft_isdigit(*prtf->fmt))
        {
            prtf->args.width = ft_atoi(prtf->fmt);
            prtf->fmt += ft_numlen(prtf->args.width);
        }
        if (CMP(*prtf->fmt, '.'))
        {
            prtf->fmt++;
            if (ft_isdigit(*prtf->fmt))
            {
                prtf->args.precision = ft_atoi(prtf->fmt);
                prtf->fmt += ft_numlen(prtf->args.precision);
            }
        }
        return ;
    }
}


void    parse_f(va_list args, t_printf *prtf)
{
    parse_flags(args, prtf);
    printf_get_widthcision(prtf, args);
    printf_get_length(prtf, args);
    printf_get_spec(prtf, args);
    //parse width /[.]precision
    // size
    // type
}