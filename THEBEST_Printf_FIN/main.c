/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saolivei <saolivei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/24 15:45:52 by saolivei          #+#    #+#             */
/*   Updated: 2019/02/25 17:28:38 by saolivei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "src/ft_printf.h"
#include <limits.h>

#define CHAR '\t'

int main(int c, char **v)
{
    double dub = 42.268;
    long double ldub = 42424242.0002;

    (void)v;
    if (c == 1)
    {
        ft_printf("*\n");
        ft_printf("%c", 42);
        ft_printf("Kashim a %c histoires à raconter", 1001);
        ft_printf("Il fait au moins %c\n", -8000);
        ft_printf("%c", -0);
        ft_printf("%c", 0);
        ft_printf("%c\n", INT_MAX);
        ft_printf("%c\n", 'c');
        ft_printf("%c\n", '\n');
        ft_printf("%c", 'l');
        ft_printf("%c", 'y');
        ft_printf("%c", ' ');
        ft_printf("%c", 'e');
        ft_printf("%c", 's');
        ft_printf("%c", 't');
        ft_printf("%c", ' ');
        ft_printf("%c", 'f');
        ft_printf("%c", 'a');
        ft_printf("%c", 'n');
        ft_printf("%c", 't');
        ft_printf("%c", 'a');
        ft_printf("%c", 's');
        ft_printf("%c", 't');
        ft_printf("%c", 'i');
        ft_printf("%c", 'q');
        ft_printf("%c", 'u');
        ft_printf("%c", 'e');
        ft_printf("%c\n", '!');
        ft_printf("%c\n", '\r');
        ft_printf("%c\n", '\t');
        ft_printf("*\n");
        ft_printf("This is a string %s\n%%\n%d\n%i\n%x\n%X\n%o\n%c", "with a custom string\n", 42, 24, 15, 15, 72, CHAR);
        ft_printf("This is a string %s\n*%%*\n*%d*\n*%i*\n*%x*\n*%X*\n*%o*\n*%c*", "with a custom string\n", 42, 24, 15, 15, 72, CHAR);
        ft_printf("This is a string %5s\n*%5%*\n*%5d*\n*%lli*\n*%5hx*\n*%5X*\n*%5ho*\n*%5c*", "with a custom string\n", 42, 21745428588468LL, 15, 15, 72, CHAR);
        ft_printf("This is a string %-5s\n*%-5%*\n*%+-5d*\n*%+-5i*\n*%-5x*\n*%-5X*\n*%+-5o*\n*%-5c*", "with a custom string\n", 42, 24, 15, 15, 72, CHAR);
        ft_printf("This is a string %.5s\n*%.5%*\n*%.5d*\n*%.5i*\n*%.5x*\n*%.5X*\n*%.5o*\n*%.5c*", "with a custom string\n", 42, 24, 15, 15, 72, CHAR);
        ft_printf("This is a string %-.5s\n*%-.5%*\n*%-.5d*\n*%-.5i*\n*%-.5x*\n*%-.5X*\n*%-.5o*\n*%-.5c*", "with a custom string\n", 42, 24, 15, 15, 72, CHAR);
        ft_printf("\n\n\tlets print floats \n\t*%10.1lf*\n\t*%1.10lf*\n\t*%.15lf*\n\t*%.lf*\n\t*%6.7lf*", dub, dub, dub, dub, dub);
        ft_printf("\n\n\tlets print floats \n\t*%10.1f*\n\t*%1.10f*\n\t*%.15f*\n\t*%.f*\n\t*%6.7f*\n\t*%.f*", dub, dub, dub, dub, dub, (double)0.0);
        ft_printf("\n\n\tlets print floats \n\t*%10.1Lf*\n\t*%1.10Lf*\n\t*%.15Lf*\n\t*%.Lf*\n\t*%6.7Lf*\n\t*%.Lf*", dub, dub, dub, dub, dub, (double)0.0);
        ft_printf("\n\n\tlets print floats \n\t*%10.1Lf*\n\t*%1.10Lf*\n\t*%.15Lf*\n\t*%.Lf*\n\t*%6.7Lf*\n\t*%.Lf*", ldub, ldub, ldub, ldub, ldub, (double)0.0);  
        ft_printf("\n\npointers : \n*%p*\n*%10p*\n*%15p*\n*%20p*\n", &dub, &ldub, &"string", 9999999999);
        ft_printf("idk, random tests to please the user :shrug: \n*%-5%*\n*%.0o*\n*%#.X" , 0 , 0);
        ft_printf("\n%u\n%u", 1245787, 16548945);
    }
    else
    {
        printf("*\n");
        printf("%c", 42);
        printf("Kashim a %c histoires à raconter", 1001);
        printf("Il fait au moins %c\n", -8000);
        printf("%c", -0);
        printf("%c", 0);
        printf("%c\n", INT_MAX);
        printf("%c\n", 'c');
        printf("%c\n", '\n');
        printf("%c", 'l');
        printf("%c", 'y');
        printf("%c", ' ');
        printf("%c", 'e');
        printf("%c", 's');
        printf("%c", 't');
        printf("%c", ' ');
        printf("%c", 'f');
        printf("%c", 'a');
        printf("%c", 'n');
        printf("%c", 't');
        printf("%c", 'a');
        printf("%c", 's');
        printf("%c", 't');
        printf("%c", 'i');
        printf("%c", 'q');
        printf("%c", 'u');
        printf("%c", 'e');
        printf("%c\n", '!');
        printf("%c\n", '\r');
        printf("%c\n", '\t');
        printf("*\n");
        printf("This is a string %s\n%%\n%d\n%i\n%x\n%X\n%o\n%c", "with a custom string\n", 42, 24, 15, 15, 72, CHAR);
        printf("This is a string %s\n*%%*\n*%d*\n*%i*\n*%x*\n*%X*\n*%o*\n*%c*", "with a custom string\n", 42, 24, 15, 15, 72, CHAR);
        printf("This is a string %5s\n*%5%*\n*%5d*\n*%lli*\n*%5hx*\n*%5X*\n*%5ho*\n*%5c*", "with a custom string\n", 42, 21745428588468LL, 15, 15, 72, CHAR);
        printf("This is a string %-5s\n*%-5%*\n*%+-5d*\n*%+-5i*\n*%-5x*\n*%-5X*\n*%+-5o*\n*%-5c*", "with a custom string\n", 42, 24, 15, 15, 72, CHAR);
        printf("This is a string %.5s\n*%.5%*\n*%.5d*\n*%.5i*\n*%.5x*\n*%.5X*\n*%.5o*\n*%.5c*", "with a custom string\n", 42, 24, 15, 15, 72, CHAR);
        printf("This is a string %-.5s\n*%-.5%*\n*%-.5d*\n*%-.5i*\n*%-.5x*\n*%-.5X*\n*%-.5o*\n*%-.5c*", "with a custom string\n", 42, 24, 15, 15, 72, CHAR);
        printf("\n\n\tlets print floats \n\t*%10.1lf*\n\t*%1.10lf*\n\t*%.15lf*\n\t*%.lf*\n\t*%6.7lf*", dub, dub, dub, dub, dub);
        printf("\n\n\tlets print floats \n\t*%10.1f*\n\t*%1.10f*\n\t*%.15f*\n\t*%.f*\n\t*%6.7f*\n\t*%.f*", dub, dub, dub, dub, dub, (double)0.0);
        printf("\n\n\tlets print floats \n\t*%10.1Lf*\n\t*%1.10Lf*\n\t*%.15Lf*\n\t*%.Lf*\n\t*%6.7Lf*\n\t*%.Lf*", dub, dub, dub, dub, dub, (double)0.0);
        printf("\n\n\tlets print floats \n\t*%10.1Lf*\n\t*%1.10Lf*\n\t*%.15Lf*\n\t*%.Lf*\n\t*%6.7Lf*\n\t*%.Lf*", ldub, ldub, ldub, ldub, ldub, (double)0.0);  
        printf("\n\npointers : \n*%p*\n*%10p*\n*%15p*\n*%20p*\n", &dub, &ldub, &"string", 9999999999);
        printf("idk, random tests to please the user :shrug: \n*%-5%*\n*%.0o*\n*%#.X" , 0 , 0);
        printf("\n%u\n%u", 1245787, 16548945);
    }
    printf("\n\n\t*%.15f*", ldub);
    return (1);
}