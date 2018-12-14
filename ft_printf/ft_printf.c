/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 01:32:37 by saolivei          #+#    #+#             */
/*   Updated: 2018/12/13 15:56:14 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void    ft_printhex(long long data)
{
    static char hex[] = "0123456789abcdef";
    static char        buf[50];
    char *ptr;


    while (data != 0)
    {
        *--ptr = hex[data % 16];
        data /= 16;
    }
    ft_putstr("0x");
    ft_putstr(ptr);
}

int     ft_vfprintf(FILE *stream, const char *format, va_list args)
{
    t_printf    prtf;
    char        *tmp;

    prtf.fmt = (char *)format;
    ft_vector_init(&(prtf.output), (sizeof(format)));
    while ((tmp = ft_strchr(prtf.fmt, '%')) != 0)
    {
        ft_vector_nappend(&(prtf.output), prtf.fmt, (tmp - prtf.fmt));
        prtf.fmt = tmp + 1;
        parse_f(args, &(prtf));
    }
    ft_vector_appened(&(prtf.output), prtf.fmt);
    write(stream->_fileno, &(prtf.output), prtf.output.len);
    return (prtf.output.len);
}

int     ft_printf(const char *format, ...)
{
    va_list     args;
    int         ret;
    
    va_start(args, format);
    ret = ft_vfprintf(stdout, format, args);
    va_end(args);
    return (ret);
}

void    printf_get_spec(t_printf *prtf, va_list args)
{
    int i;

    i = -1;
    t_printf_spec       g_spec[19] =
    {
        {'%', &spec_percentage},
        {'c', &spec_char},
        {'s', &spec_string},
        {'d', &spec_signed_int},
        {'i', &spec_signed_int},
        {'o', &spec_octal},
    };
    while (++i < 6)
        if (CMP(*prtf->fmt, g_spec[i].spec))
        {
            g_spec[i].func(prtf,args);
            return ;
        }
}