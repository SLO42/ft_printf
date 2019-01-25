/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsef.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 20:25:33 by saolivei          #+#    #+#             */
/*   Updated: 2019/01/23 13:25:45 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// 

void    parse_flags(t_printf *prtf)
{
    static char flags[] = "-+ #0";
    char        *tmp;

    while (++prtf->fmt != 0)
    {
        if (!(tmp = ft_strchr(flags, *prtf->fmt)))
            return ;
        else if (CMP(prtf->args.flags.f, 1))
            prtf->args.flags.f = 0;
        else if (CMP(*tmp, flags[0]))
            prtf->args.flags.left_just++;
        else if (CMP(*tmp, flags[1]))
            prtf->args.flags.prepend_sign++;
        else if (CMP(*tmp, flags[2]))
            prtf->args.flags.prepend_space++;
        else if (CMP(*tmp, flags[3]))
            prtf->args.flags.alt_form++;
        else if (CMP(*tmp, flags[4]))
            prtf->args.flags.pad_zeros++;
    }
}

void    printf_get_length(t_printf *prtf)
{
    if (*prtf->fmt == 'l')
     {
        if (*prtf->fmt + 1 == 'l')
        {
            prtf->fmt++;
            prtf->args.stats.pf_ll += 1;
        }
        else
            prtf->args.stats.pf_l += 1;
    }
    else if (*prtf->fmt == 'h')
    {
        if (*prtf->fmt + 1 == 'h')
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
                prtf->args.pre = ft_atoi(prtf->fmt);
                prtf->fmt += ft_numlen(prtf->args.pre);
            }
            else if (*prtf->fmt++ == '*')
                prtf->args.pre = va_arg(args, int);
            else if (*prtf->fmt == '-' || !(ft_islenorconv(*prtf->fmt)))
                while (!(ft_islenorconv(*prtf->fmt)))
                    prtf->fmt++;
        }
        prtf->args.pre = prtf->args.pre < 0 ? 0 : prtf->args.pre;
        return ;
    }
}

int ft_islenorconv(char value)
{
    char val[24] = "hljztLcsdioxXufFeEaAgGnp";
    char *tmp;

    if (!(tmp = ft_strchr(val, value)))
        return 0;
    return 1;
}

void    clean_parse(t_printf *prtf)
{
    prtf->args.width = 0;
    prtf->args.pre = 0;
    prtf->args.spec = 0;
    prtf->args.flags.f = 1;
    prtf->args.flags.left_just = 1;
    prtf->args.flags.prepend_sign = 1;
    prtf->args.flags.prepend_space = 1;
    prtf->args.flags.alt_form = 1;
    prtf->args.flags.pad_zeros = 1;
    prtf->args.stats.l = 1;
    prtf->args.stats.pf_hh = 1;
    prtf->args.stats.pf_h = 1;
    prtf->args.stats.pf_l = 1;
    prtf->args.stats.pf_ll = 1;
    prtf->args.stats.pf_z = 1;
}


void    parse_f(va_list args, t_printf *prtf)
{
    parse_flags(&(prtf));
    printf_get_widthcision(&(prtf), args);
    printf_get_length(&(prtf));
    printf_get_spec(&(prtf), args);
    clean_parse(&(prtf));
    //parse width /[.]precision
    // size
    // type
}