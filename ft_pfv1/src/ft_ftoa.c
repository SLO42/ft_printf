/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:15:43 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/17 17:42:00 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_nou_del(char **as)
{
	if (!as)
		return (0);
	free(*as);
	*as = NULL;
	return (1);
}

char			*ft_ftoa(long double num, t_printf *prtf)
{
	NUMS 
	char 	*firsthalf;
	char 	*result;
	int 	tmpp;

	tmpp = (PPRE > 0) ? 2 : 1;
	DIFP = (PPRE > 0) ? PPRE : 0;
	num1 = ft_ulltoa_base(num, 10);
	while (PPRE > 1)
	{
		tmpp++;
		PPRE--;
	}
	if (tmpp > 1)
	{
		firsthalf = ft_strjoin(num1, ".");
		num2 = ft_power(tmpp, (num - (int)num));
	}
	result = (num2 != NULL) ? ft_strjoin(firsthalf, num2) : ft_strdup(num1);
	if (num2 != NULL)
	{
		free(num2);
		free(firsthalf);
	}
	return ((ft_nou_del(&num1)) ? result : result);
}

char* ft_power(int power, long double dare)
{
	char *num;
	int i;

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
	// dare *= 10;
	// if ((int)dare % 10 >= 5)
	// 	num = ft_round(1, num);
// char *ft_round(short direction, char *num)
// {
// 	int i;
// 	int flag;

// 	i = 0;
// 	flag = 0;
// 	while (num[i] != 0)
// 	{
// 		if (num[i] == '.')
// 			flag = 1;
// 		i++;
// 	}
// 	i--;
// 	while (i >= 0 && num[i] == '9' && num[i] != '.')
// 	{
// 		num[i] = '0';
// 		i--;
// 	}
// 	if (flag == 1 && num[i] == '.' && i != 0)
// 		ft_itoa((ft_atoi(num)++); 

// }
