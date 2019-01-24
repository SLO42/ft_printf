/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 01:32:37 by saolivei          #+#    #+#             */
/*   Updated: 2019/01/07 17:55:09 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"


int     ft_vfprintf(int fd, const char *format, va_list args)
{
    t_printf    prtf;
    size_t      lend;

    prtf.fmt = (char *)format;
    clean_parse(&prtf);
    prtf.len = 0;
    while (*prtf.fmt != 0)
    {
        if (*prtf.fmt == '%')
            parse_f(args, &(prtf));
        else
        {
            ft_putchar_fd(*prtf.fmt, fd);
            prtf.len++;
            prtf.fmt++;
        }
    }
    //ft_vector_appened(&(prtf.output), prtf.fmt);
    lend = ft_strlen(prtf.fmt);
    prtf.len += lend;
    write(fd, &(prtf.fmt), lend);
    return (prtf.len);
}

int     ft_printf(const char *format, ...)
{
    va_list     args;
    int         ret;
    
    va_start(args, format);
    ret = ft_vfprintf(STDOUT_FILENO, format, args);
    va_end(args);
    return (ret);
}

void    printf_get_spec(t_printf *prtf, va_list args)
{
    int i;
    char values[19] = "%csdio";
    char *spot;
    i = -1;

    spot = ft_strchr(values, *prtf->fmt);
    if (CMP(spot,"%"))
        return (spec_percentage(prtf));
    else if (CMP(spot,"c"))
        return (spec_char(prtf, args));
    else if (CMP(spot, "s"))
        return (spec_string(prtf, args));
    else if (CMP(spot, "d") || CMP(spot, "i"))
        return (spec_signed_int(prtf, args));

}