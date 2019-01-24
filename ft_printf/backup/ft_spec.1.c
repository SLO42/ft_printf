/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:36:11 by saolivei          #+#    #+#             */
/*   Updated: 2019/01/07 18:00:02 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    spec_percentage(t_printf *p)
{
    if (MO(MNO(p->args.flags.f, p->args.stats.l), p->args.pre, p->args.width))
        //print the error for not having format for --- %% ---
    write(1, "%", 1);
    p->len++;
}

void    spec_char(t_printf *prtf, va_list args)
{
    wchar_t tmp[2];

    if (NOT1(prtf->args.stats.pf_l))
    {
        tmp[0] = va_arg(args, unsigned int);
        write(1, &tmp, 1);
        prtf->len++;
    }
    else
        write(1, va_arg(args, char*), 1);
}

void    spec_string(t_printf *prtf, va_list args)
{
    char *tmp;

    tmp = va_arg(args, char*);
    if (NOT1(prtf->args.stats.pf_l))
    {
        write(1, &tmp, prtf->args.pre);
        prtf->len += prtf->args.pre;
    }
    else
    {
        ft_putstr(tmp);
        prtf->len += ft_strlen(tmp);
    }
}

void    spec_signed_int(t_printf *prtf, va_list args)
{
    char tmp;
    char *tmps;

    if (NOT1(prtf->args.stats.pf_hh))
    {
        tmp = va_arg(args, unsigned int);
        write(1, &tmp, 1);
        prtf->len++;
    }
    else if (NOT1(prtf->args.stats.pf_h) && prtf->args.width != 0)
    {
        write(1, ft_shtostr(va_arg(args, unsigned int)), prtf->args.width);
        prtf->len += prtf->args.width;
    }
    else if (NOT1(prtf->args.stats.pf_h))
    {
        tmps = ft_shtostr(va_arg(args, unsigned int));
        ft_putstr(&tmp);
        prtf->len += ft_strlen(tmps);
    }
    else
    {
        tmps = ft_shtostr(va_arg(args, unsigned int));
        ft_putstr(tmps);
        prtf->len += ft_strlen(tmps);
    }
}
