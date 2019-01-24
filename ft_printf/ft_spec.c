    /* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_spec.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 14:36:11 by saolivei          #+#    #+#             */
/*   Updated: 2019/01/07 13:48:34 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    spec_percentage(t_printf *p)
{
    if (MO(MNO(p->args.flags.f, p->args.stats.l), p->args.pre, p->args.width))
        //print the error for not having format for --- %% ---
    ft_lstadd(p->output, ft_lstnew("%", 1));
}

void    spec_char(t_printf *prtf, va_list args)
{
    int             dif;

    dif = ft_cont_less_width(1, prtf->args.width);
    if (dif)
    {
        if (NOT1(prtf->args.flags.left_just))
        {
            ft_lstadd(&(prtf->output), ft_lstnew(VARGUCUINT(), 1));
            create_width(&(prtf->output), dif, 7);
        }
        else
        {
            create_width(&(prtf->output), dif, 7);
            ft_lstadd(&(prtf->output), ft_lstnew(VARGUCUINT(), 1));
        }
    }
    else
        ft_lstadd(&(prtf->output), ft_lstnew(VARGUCUINT(), 1));
}

void    spec_string(t_printf *prtf, va_list args)
{
    char    *tmp;
    int     dif;

    tmp = va_arg(args, char *);
    if (ft_strlen(tmp) > prtf->args.pre && prtf->args.pre != 0)
        tmp = ft_strsub(tmp, 0, prtf->args.pre);
    if ((dif = ft_cont_less_width(ft_strlen(tmp), prtf->args.width)) > 0)
    {
        if (NOT1(prtf->args.flags.left_just))
        {
            ft_lstadd(&(prtf->output), ft_lstnew(tmp, ft_strlen(tmp)));
            create_width(&(prtf->output), dif, 7);
        }
        else
        {
            create_width(&(prtf->output), dif, 0);
            ft_lstadd(&(prtf->output), ft_lstnew(tmp, ft_strlen(tmp)));
        }
    }
    else
        ft_lstadd(&(prtf->output), ft_lstnew(tmp, ft_strlen(tmp)));
}

void    create_width(t_printf *prtf, int amount, int or)
{
    char    *tmp;
    int     i;

    i = 0;
    tmp = ft_strnew(amount);
    if ((NOT1(prtf->args.flags.pad_zeros) && or != 7) || or == 1)
    {
        while (--amount)
            tmp[i++] = '0';
        ft_lstadd(prtf->output, ft_lstnew(tmp,amount));
    }
    else
    {
        while (--amount)
            tmp[i++] = ' ';
        ft_lstadd(prtf->output, ft_lstnew(tmp, amount));
    }
}

int ft_cont_less_width(size_t size, int width)
{
    if (size < width)
    {
        return (width - size);
    }
    return (0);
}


void    spec_signed_int(t_printf *prtf, va_list args)
{

    if (NOT1(prtf->args.stats.pf_hh))
        spec_signed_int_hh(prtf, args);
    else if (NOT1(prtf->args.stats.pf_h))
        spec_signed_int_h(prtf, args);
    else if (NOT1(prtf->args.stats.pf_l))
        spec_signed_int_l(prtf, args);
    else if (NOT1(prtf->args.stats.pf_ll))
        spec_signed_int_ll(prtf, args);
    else
        spec_signed_int_int(&(prtf), args);
}

void    spec_signed_int_int(t_printf *prtf, va_list args)
{
    int num;
    int dif;

    num = (int)va_arg(args, signed int);
    if (prtf->args.pre == 0 && (num == 0 || !(num)))
        return ;
    if ((dif = ft_cont_less_width(ft_numlen(num), prtf->args.pre)) > 0)
    {
        if (NOT1(prtf->args.flags.left_just))
        {
            ft_lstadd(&(prtf->output), ft_lstnew(ft_itoa(num), ft_numlen(num)));
            create_width(&(prtf), dif, 7);
        }
        else
        {
            create_width(&(prtf), dif, 1);
            ft_lstadd(&(prtf->output), ft_lstnew(ft_itoa(num), ft_numlen(num)));
        }
    }
    else
        ft_lstadd(&(prtf->output), ft_lstnew(ft_itoa(num), ft_numlen(num)));

}
void    spec_signed_int_h(t_printf *prtf, va_list args)
{
    int     dif;
    short   num;

    num = va_arg(args, signed int);
    if (prtf->args.pre == 0 && (num == 0 || !(num)))
        return (ft_lstadd(prtf->output, ft_lstnew(NULL, 0)));
    else
    {
        if ((dif = ft_cont_less_width(ft_numlen(num), prtf->args.pre) > 0))
            data = ft_appened_data_perc(prtf, num, dif, ft_numlen(num));
        if ((dif = ft_cont_less_width(ft_numlen(data), prtf->args.width) > 0))
            ft_lstadd(prtf->output, ft_lstnew(ft_appened_data(prtf, data, dif, ft_numlen(data)), ft_numlen(data) + dif));
        else
            ft_lstadd(prtf->output, ft_lstnew(data, ft_strlen(data)));
    }
}

void    spec_signed_int_hh(t_printf *prtf, va_list args)
{
    int         tmp;
    int         dif;
    void        *data;

    tmp = va_arg(args, signed int);
    if (prtf->args.pre == 0 && (tmp == 0 || tmp == NULL))
        return (ft_lstadd(prtf->output, ft_lstnew(NULL, 0)));
    else
    {
        data = ft_memcpy(data, tmp, ft_numlen(tmp));
        if ((dif = ft_cont_less_width(ft_numlen(tmp), prtf->args.pre)) > 0)
            data = ft_appened_data_perc(prtf, tmp, dif, ft_numlen(tmp));
        if ((dif = ft_cont_less_width(ft_numlen(data), prtf->args.width)) > 0)
            ft_lstadd(prtf->output, ft_lstnew(ft_appened_data(prtf, data, dif, ft_numlen(data)), ft_numlen(data) + dif));
        else
            ft_lstadd(prtf->output, ft_lstnew(data, ft_numlen(data)));
    }
}