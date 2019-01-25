/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:41:57 by saolivei          #+#    #+#             */
/*   Updated: 2019/01/23 15:20:44 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"
# define NOT1(a)(a != 1)
# define MNO(a, b)(NOT1(a) || NOT1(b))
# define MO(c, d, e)( c || d || e)
# define CMP(x,y)(x == y)
# define VARGUINT()((unsigned char)va_arg(args, unsigned int))

typedef struct      s_printf_flags
{
    uint8_t         f : 1;
    uint8_t         left_just : 1;
    uint8_t         prepend_sign : 1;
    uint8_t         prepend_space : 1;
    uint8_t         alt_form : 1;
    uint8_t         pad_zeros : 1;
}                   t_printf_flags;

typedef struct      s_printf_stats
{
    uint8_t         l: 1;
    uint8_t	    	pf_hh : 1;
	uint8_t	    	pf_h : 1;
	uint8_t	    	pf_l : 1;
	uint8_t	    	pf_ll : 1;
	uint8_t	    	pf_z : 1;
}                   t_printf_stats;

typedef struct      s_printf_args
{
	t_printf_flags	flags;
	int				width;
	int				pre;
	t_printf_stats  stats;
	char			spec;
}					t_printf_args;

typedef struct      s_printf
{
    t_list          *output;
    char            *fmt;
    t_printf_args	args;
    size_t          len;
}                   t_printf;

int                 ft_printf(char const *format, ...);
void                printf_get_spec(t_printf *prtf, va_list args);
void                printf_get_length(t_printf *prtf);
void                parse_flags(t_printf *prtf);
void                parse_f(va_list args, t_printf *prtf);
int                 ft_vfprintf(FILE *stream, const char *format, va_list args);

//Append the result to the vector
void	spec_percentage(t_printf *prtf);
void	spec_char(t_printf *prtf, va_list args);
void	spec_string(t_printf *prtf, va_list args);
void	spec_signed_int(t_printf *prtf, va_list args);
void	spec_octal(t_printf *prtf, va_list args);
void    clean_parse(t_printf *prtf);

char    *ft_shtostr(signed int num);

#endif