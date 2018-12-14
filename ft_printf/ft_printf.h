/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:41:57 by saolivei          #+#    #+#             */
/*   Updated: 2018/12/13 15:08:46 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include "libft/libft.h"
# define CMP(x,y)(x == y)

typedef struct      s_printf
{
    t_vector        output;
    char            *fmt;
    t_printf_args	args;
}                   t_printf;

typedef struct      s_printf_flags
{
    uint8_t         left_just : 1;
    uint8_t         prepend_sign : 1;
    uint8_t         prepend_space : 1;
    uint8_t         alt_form : 1;
    uint8_t         pad_zeros : 1;
}                   t_printf_flags;

typedef struct      s_printf_stats
{
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
	int				precision;
	t_printf_stats  stats;
	char			spec;
}					t_printf_args;

typedef void        (*t_spec_func)(t_printf *prtf, va_list arg);

typedef struct      s_printf_spec
{
    char            spec;
    t_spec_func     func;
}                   t_printf_spec;

int                 ft_printf(char const *format, ...);
void                printf_get_spec(t_printf *prtf, va_list args);
void                printf_get_length(t_printf *prtf, va_list args);
void                parse_flags(va_list args, t_printf *prtf);
void                parse_f(va_list args, t_printf *prtf);
int                 ft_vfprintf(FILE *stream, const char *format, va_list args);

void                ft_printhex(long long data);

//Append the result to the vector
void	spec_percentage(t_printf *prtf, va_list args);
void	spec_char(t_printf *prtf, va_list args);
void	spec_string(t_printf *prtf, va_list args);
void	spec_signed_int(t_printf *prtf, va_list args);
void	spec_octal(t_printf *prtf, va_list args);

#endif