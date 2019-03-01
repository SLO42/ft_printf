#include <stdio.h>
#include "src/ft_printf.h"

int main()
{
    char *s1;
    char *s2;
    char *s3;
    char *s4;
    char c1;
    char c2;
    char c3;
    char c4;
    long long ll_min;
    long long ll_max;
    long long ll_under;
    long long ll_over;
    unsigned long long ullong_max;
    unsigned long long ull;
    unsigned long ul_max;
    unsigned long ul2;
    unsigned int ui_max;
    unsigned int ui2;
    unsigned int ui3;
    int i;
     
    c1 = 0;
    c2 = 255;
    c3 = 9999;
    c4 = NULL;
    s1 = "Hello";
    s2 = " ";
    s3 = "World";
    s4 = NULL;

    ll_min = -9223372036854775808LL;
    ll_max = 9223372036854775807LL;
    ll_under = -9223372036854775809LL;
    ll_over = 9223372036854775808LL;

    ullong_max = 18446744073709551615ULL;
    ull = 9999999999999999999ULL;

    ul_max = 18446744073709551615UL;
    ul2 = 0UL;

    ui_max = 4294967295;
    ui2 = 4294967296;
    ui3 = 4294967297;

    i = 0;
    ft_printf("\n\n\n");
    printf("\n::4string::%d... %s%s%s%s", i, s1, s2, s3, s4);
    ft_printf("\n::4string::%d... %s%s%s%s", i++, s1, s2, s3, s4);
    ft_printf("\n\n\n");

    ft_printf("\n\n\n");
    ft_printf("\t\toctal std::ft_printf\n\n");

    ft_printf("Testing %d octal                     :%o \n", i, i++);
    ft_printf("Testing %d octal                  .0 :%.0o \n", i, i++);
    ft_printf("Testing %d octal                 0.0 :%0.0o \n", i, i++);
    ft_printf("Testing %d octal                00.0 :%00.0o \n", i, i++);
    ft_printf("Testing %d octal                 .20 :%.20o \n", i, i++);
    ft_printf("Testing %d octal                  20 :%20o \n", i, i++);
    ft_printf("Testing %d octal       left_just .20 :%-.20o \n", i, i++);
    ft_printf("Testing %d octal       left_just  20 :%-20o \n", i, i++);
    ft_printf("Testing %d octal   left_just zero 20 :%-020o \n", i, i++);
    ft_printf("Testing %d octal               15.20 :%15.20o \n", i, i++);
    ft_printf("Testing %d octal               20.15 :%20.15o \n", i, i++);
    ft_printf("Testing %d octal    left_just  15.20 :%-15.20o \n", i, i++);
    ft_printf("Testing %d octal    left_just  20.15 :%-20.15o \n", i, i++);
    ft_printf("Testing %d octal a               .20 :%#.20o \n", i, i++);
    ft_printf("Testing %d octal a                20 :%#20o \n", i, i++);
    ft_printf("Testing %d octal a             20.10 :%#20.10o \n", i, i++);
    ft_printf("Testing %d octal a             10.20 :%#10.20o \n", i, i++);
    ft_printf("Testing %d octal a     left_just .20 :%#-.20o \n", i, i++);
    ft_printf("Testing %d octal a     left_just  20 :%#-20o \n", i, i++);
    ft_printf("Testing %d octal a left_just zero 20 :%#-020o \n", i, i++);
    ft_printf("Testing %d octal        0        0.0 :%0.0o \n", i, 0);
    ft_printf("Testing %d octal        0         .0 :%.0o \n", i, 0);
    ft_printf("Testing %d octal        0            :%o \n", i, 0);

    ft_printf("\n\n\n");
    ft_printf("\t\toctal std::ft_printf\n\n");

    ft_printf("Testing %d octal                     :%o \n", i, i++);
    ft_printf("Testing %d octal                  .0 :%.0o \n", i, i++);
    ft_printf("Testing %d octal                 0.0 :%0.0o \n", i, i++);
    ft_printf("Testing %d octal                00.0 :%00.0o \n", i, i++);
    ft_printf("Testing %d octal                 .20 :%.20o \n", i, i++);
    ft_printf("Testing %d octal                  20 :%20o \n", i, i++);
    ft_printf("Testing %d octal       left_just .20 :%-.20o \n", i, i++);
    ft_printf("Testing %d octal       left_just  20 :%-20o \n", i, i++);
    ft_printf("Testing %d octal   left_just zero 20 :%-020o \n", i, i++);
    ft_printf("Testing %d octal               15.20 :%15.20o \n", i, i++);
    ft_printf("Testing %d octal               20.15 :%20.15o \n", i, i++);
    ft_printf("Testing %d octal    left_just  15.20 :%-15.20o \n", i, i++);
    ft_printf("Testing %d octal    left_just  20.15 :%-20.15o \n", i, i++);
    ft_printf("Testing %d octal a               .20 :%#.20o \n", i, i++);
    ft_printf("Testing %d octal a                20 :%#20o \n", i, i++);
    ft_printf("Testing %d octal a             20.10 :%#20.10o \n", i, i++);
    ft_printf("Testing %d octal a             10.20 :%#10.20o \n", i, i++);
    ft_printf("Testing %d octal a     left_just .20 :%#-.20o \n", i, i++);
    ft_printf("Testing %d octal a     left_just  20 :%#-20o \n", i, i++);
    ft_printf("Testing %d octal a left_just zero 20 :%#-020o \n", i, i++);
    ft_printf("Testing %d octal        0        0.0 :%0.0o \n", i, 0);
    ft_printf("Testing %d octal        0         .0 :%.0o \n", i, 0);
    ft_printf("Testing %d octal        0            :%o \n", i, 0);



}