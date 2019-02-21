/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:15:43 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/21 11:46:46 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*ft_power(int power, long double dare)
{
	char	*num;
	int		i;

	i = 0;
	num = ft_strnew(power);
	while (--power)
	{
		if (i % 5 == 0)
			dare -= (int)dare;
		dare *= 10;
		num[i] = ((int)dare % 10) + 48;
		i++;
	}
	return (num);
}

static char		*round_help(char *num, int index)
{
	while (index >= 0 && num[index] == '9' && num[index] != '.')
	{
		num[index] = '0';
		index--;
	}
	if (--index > 0 && num[index] == '.')
	{
		while (index >= 0 && num[index] == '9')
		{
			num[index] = '0';
			index--;
		}
		if (index == 0 && num[0] == '9')
		{
			num = ft_recalloc(num, ft_strlen(num), ft_strlen(num) + 1);
			num[0] = '1';
			num[1] = '0';
		}
	}
	if (num[index + 1] != '\0' && index >= 0 && num[index] != '9')
		num[index] = ((int)num[index] + 1);
	else if (num[index] >= '5' && num[index] <= '8')
		num[index] = ((int)num[index] + 1);
	return (num);
}

static char		*round_help_before_dot(char *num, int index)
{
	while (--index >= 0 && num[index] == '9')
		num[index] = '0';
	if (index == 0 && num[0] == '9')
	{
		num = ft_recalloc(num, ft_strlen(num), ft_strlen(num) + 1);
		num[0] = '1';
		num[1] = '0';
	}
	else
		num[index] = ((int)num[index] + 1);
	return (num);
}

char			*ft_round(char *num)
{
	int i;
	int flag;

	i = 0;
	flag = 0;
	while (num[i] != 0)
	{
		flag = num[i] == '.' ? 1 : flag;
		if (CHECK_GR5(num, i) && num[i + 2] == '\0')
		{
			num[i + 1] = '0';
			num[i] = '0';
			while (num[--i] == '9')
				num[i] = '0';
			if (num[i] <= '8')
				num[i] = (int)num[i] + 1;
			else if (i > 0 && num[i] == '.')
				return (round_help_before_dot(num, i));
			return (num);
		}
		i++;
	}
	i--;
	return (flag ? round_help(num, i) : num);
}

char			*ft_ftoa(long double num, t_printf *prtf)
{
	char	*firsthalf;
	char	*result;
	char	*num2;

	NUMS;
	tmpp = (PPRE > 0) ? 2 : 1;
	DIFP = (PPRE > 0) ? PPRE : 0;
	num1 = ft_ulltoa_base(num, 10);
	while (PPRE > 1)
	{
		tmpp++;
		PPRE--;
	}
	if ((num2 = NULL) == NULL && tmpp > 1)
	{
		firsthalf = ft_strjoin(num1, ".");
		num2 = ft_power(tmpp, (num - (int)num));
	}
	result = ft_round(ROUND_CHECK(num1, num2, firsthalf));
	if (num2 != NULL)
	{
		free(num2);
		free(firsthalf);
	}
	return ((ft_nou_del(&num1)) ? result : result);
}
