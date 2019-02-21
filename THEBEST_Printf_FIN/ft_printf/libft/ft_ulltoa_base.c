/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ulltoa_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 16:48:48 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/19 16:31:04 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char		*ft_ulltoaexc(uint32_t base)
{
	long		num;
	int			i;
	const char	tab[16] = "0123456789ABCDEF";
	char		*ret;

	i = 0;
	num = ULLONG_MAX;
	while (num > 0)
	{
		i++;
		num /= base;
	}
	if (!(ret = ft_strnew(i)))
		return (NULL);
	while (--i)
		ret[i] = tab[base - 1];
	return (ret);
}

char			*ft_ulltoa_base(unsigned long long n, uint32_t base)
{
	int							len;
	char						*nums;
	const char					tab[16] = "0123456789ABCDEF";
	const unsigned long long	max = 18446744073709551615ULL;

	if (base < 2 || base > 16)
		return (NULL);
	len = ft_ull_len_base(n, base);
	if (n == max)
		return (ft_ulltoaexc(base));
	if (!(nums = ft_strnew(len)))
		return (NULL);
	if (len > 1)
		while (--len - 1 >= 0)
		{
			nums[len - 1] = tab[(n % base)];
			n /= base;
		}
	else
		nums[0] = tab[(n % base)];
	return (nums);
}
