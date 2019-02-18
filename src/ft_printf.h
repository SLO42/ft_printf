/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/10 10:41:57 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/17 17:42:19 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H
#include <stdarg.h>
#include <stdio.h>
#include "../libft/libft.h"
#define NOT1(a) (a != 1)
#define MNO(a, b) (NOT1(a) || NOT1(b))
#define MO(c, d, e) (c || d || e)
#define CMP(x, y) (x == y)
#define UNI(a) ((unsigned int)a)
#define PFLAGSPACE prtf->args->flags->prepend_space
#define PFLAGSIGN prtf->args->flags->prepend_sign
#define PFLEN prtf->args->stats->l
#define DIFW prtf->args->stats->difw
#define DIFP prtf->args->stats->difp
#define PWIDTH prtf->args->width
#define PPRE prtf->args->pre
#define LSTADD(c, s) (ft_vector_nappend((prtf->output), c, s))
#define SPEC prtf->args->spec
#define PRECK(c, s) (precheck(c, s, prtf))
#define IFHEX(c, s) (SPEC == 'x' ? PRECK(ft_strlower(c), s) : PRECK(c, s))
#define ADDHIGHHEX ft_prtf_add("0X", 2, prtf)
#define ADDLOWHEX ft_prtf_add("0x", 2, prtf)
#define ALTHEX SPEC == 'x' ? ADDLOWHEX : ADDHIGHHEX
#define IFALT(s) (if_alt(prtf, s))
#define ADDLST(c, s) (ft_prtf_add(c, s, prtf))
#define CONTENT prtf->output->data
#define CONTENT_SIZE prtf->output->len
#define WRITE_TO_STREAM write(1, CONTENT, CONTENT_SIZE)
#define ULL_FLOAT_TO_BASE ft_ulltoa_base(ft_power(tmpp, (num - (int)num)), 10)
#define NUMS char *num1 = NULL; char *num2 = NULL;
#define ALLOC_FLAGS !(prtf->args->flags = ft_memalloc(sizeof(t_printf_flags)))
#define ALLOC_STATS !(prtf->args->stats = ft_memalloc(sizeof(t_printf_stats)))
#define ALLOC_LIST !(prtf->output = ft_memalloc(sizeof(t_vector)))
#define ALLOC_ARGS !(prtf->args = ft_memalloc(sizeof(t_printf_args)))
#define DIFSZ(a, b) (((size_t)a < (size_t)b) ? b - a : 0)

typedef struct 		s_printf_flags
{
	short 		f;
	short 		left_just;
	short 		prepend_sign;
	short 		prepend_space;
	short 		alt_form;
	short 		pad_zeros;
} 					t_printf_flags;

typedef struct 		s_printf_stats 
{
	short 		l;
	short 		pf_hh;
	short 		pf_h;
	short 		pf_l;
	short 		pf_L;
	short 		pf_ll;
	int 			difw;
	int 			difp;
} 					t_printf_stats;

typedef struct 		s_printf_args
{
	t_printf_flags 	*flags;
	t_printf_stats 	*stats;
	int 			width;
	int 			pre;
	char 			spec;
} 					t_printf_args;

typedef struct 		s_printf
{
	t_vector 		*output;
	t_printf_args 	*args;
	char 			*fmt;
	size_t 			len;
} 					t_printf;

//int  ft_size_dif(size_t size, int width); RENDEDRED USESLESS WITH "DIFSZ" MACRO
int 				ft_printf(char const *format, ...);
int 				ft_vfprintf(const char *format, va_list args);
char				*ft_power(int power, long double dare);
void 				printf_get_spec(t_printf *prtf, va_list args);
void				free_it_all(t_printf *prtf);
void				ft_exit(short num, t_printf *prtf);
void				ft_del_prtf(t_printf *prtf);

void 				parse_f(va_list args, t_printf *prtf);
int 				if_alt(t_printf *prtf, int size);
int					ft_chr_in_str(const char *table, int tab_size, char c);
char 				*ft_ftoa(long double num, t_printf *prtf);
int					ft_nou_del(char **as);
//Append the result to the vector | Checking before adding.
void 				precheck(char *str, size_t size, t_printf *prtf);
void 				ft_prtf_add(char *str, size_t size, t_printf *prtf);
//CLEAN
void 				clean_parse(t_printf *prtf);
//default create elem for space/0/0x
void 				create_width(t_printf *prtf, int amount, int or);
//used for checking if is altform or any missing info.
void 				first_width(t_printf *prtf, int amount, int or);
//floats
void 				spec_float(t_printf *prtf, va_list args);
void 				spec_float_L(t_printf *prtf, va_list args);
void 				spec_float_float(t_printf *prtf, va_list args);
void 				spec_float_l(t_printf *prtf, va_list args);
//spec precentage
void 				spec_percentage(t_printf *prtf);
//char and char*
void 				spec_char(t_printf *prtf, va_list args);
void 				spec_string(t_printf *prtf, va_list args);
//signed int
void 				spec_signed_int(t_printf *prtf, va_list args);
void 				spec_signed_int_int(t_printf *prtf, va_list args);
void 				spec_signed_int_l(t_printf *prtf, va_list args);
void 				spec_signed_int_ll(t_printf *prtf, va_list args);
void 				spec_signed_int_h(t_printf *prtf, va_list args);
void 				spec_signed_int_hh(t_printf *prtf, va_list args);
//unsigned int
void 				spec_unsigned_int(t_printf *prtf, va_list args);
void 				spec_unsigned_int_u_uint(t_printf *prtf, va_list args);
void 				spec_unsigned_int_u_h(t_printf *prtf, va_list args);
void 				spec_unsigned_int_u_hh(t_printf *prtf, va_list args);
void 				spec_unsigned_int_u_l(t_printf *prtf, va_list args);
void 				spec_unsigned_int_u_ll(t_printf *prtf, va_list args);
//unsigned int -> hex
void				spec_hex_helper(t_printf *prtf, char *num);
void 				spec_unsigned_int_x_uint(t_printf *prtf, va_list args);
void 				spec_unsigned_int_x_h(t_printf *prtf, va_list args);
void 				spec_unsigned_int_x_hh(t_printf *prtf, va_list args);
void 				spec_unsigned_int_x_l(t_printf *prtf, va_list args);
void 				spec_unsigned_int_x_ll(t_printf *prtf, va_list args);
//unsigned int -> octet
void 				spec_octal(t_printf *prtf, va_list args);
void 				spec_unsigned_int_o_uint(t_printf *prtf, va_list args);
void			 	spec_unsigned_int_o_h(t_printf *prtf, va_list args);
void 				spec_unsigned_int_o_hh(t_printf *prtf, va_list args);
void 				spec_unsigned_int_o_l(t_printf *prtf, va_list args);
void 				spec_unsigned_int_o_ll(t_printf *prtf, va_list args);
//void* -> address
void 				spec_pointer(t_printf *prtf, va_list args);
//creating padding and 0x
void 				create_width(t_printf *prtf, int amount, int or);

#endif