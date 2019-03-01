/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lltoa.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/28 15:04:59 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/14 21:14:01 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

static char *ft_lltoaEXCEPTIONS(uint32_t base)
{
    long num;
    int i;
    const char tab[16] = "0123456789ABCDEF";
    char *ret;

    i = 0;
    num = LLONG_MIN;
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

char	*ft_lltoa(long long n)
{
	int		len;
	char	*nums;
	int		flag;

	flag = 0;
	len = ft_numlen(n);
	if (n == LLONG_MIN)
		return (ft_lltoaEXCEPTIONS(10));
	if (n < 0)
		flag = 1;
	if (!(nums = (char*)malloc(sizeof(char) * (len + 1 + flag))))
		return (NULL);
	nums[len + flag] = '\0';
	while (--len + flag >= flag)
	{
		if (n < 0)
			nums[len + flag] = ((n % 10) * -1) + 48;
		else
			nums[len + flag] = (n % 10) + 48;
		n /= 10;
	}
	if (flag == 1)
		nums[0] = '-';
	return (nums);
}
