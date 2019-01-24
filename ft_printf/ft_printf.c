/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/07 01:32:37 by saolivei          #+#    #+#             */
/*   Updated: 2019/01/22 15:15:20 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int     ft_vfprintf(FILE *stream, const char *format, va_list args)
{
    t_printf    prtf;
    char        *tmp;

    prtf.fmt = (char *)format;
    prtf.output = ft_lstnew(NULL, 0);
    prtf.len = 0;
    while ((tmp = ft_strchr(prtf.fmt, '%')) != 0)
    {
        ft_lstadd(prtf.output, ft_lstnew(prtf.fmt, tmp - prtf.fmt));
        //prtf.output = ft_lstnew(prtf.fmt, tmp - prtf.fmt);//ft_vector_nappend(&(prtf.output), prtf.fmt, (tmp - prtf.fmt));
        prtf.fmt = tmp;
        parse_f(args, &(prtf));
    }
    if (!prtf.output)
        prtf.output = ft_lstnew(prtf.fmt, ft_strlen(prtf.fmt));
    else
        ft_lstadd(prtf.output, ft_lstnew(prtf.fmt, ft_strlen(prtf.fmt)));
    while (prtf.output)
    {
        write(stream->_file, &prtf.output->content, prtf.output->content_size);
        prtf.len += prtf.output->content_size;
        prtf.output = prtf.output->next;
    }
    return (prtf.len);
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
    char values[19] = "%csdioxXufFeEaAgGnp";
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