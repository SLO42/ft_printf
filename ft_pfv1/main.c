#include <stdio.h>
#include "src/ft_printf.h"

int main(void)
{
    char a;
    long oc;
    int i;
    int d;
    void *p;
    float fat = 123.321;
    static double f = 123456789.0125;
    static long double lf = 123456789.0125;
    i = 97;

    a = 'a';
    oc = 4294967296L;
    p = &i;
    d = 0;

    // ft_printf("\n\n\n");
    // ft_printf("\toctal std::ft_printf\n\n");

    // ft_printf("Testing %d octal                 .20 :%.20o \n", d++, oc);
    // ft_printf("Testing %d octal                  20 :%20o \n", d++, oc);
    // ft_printf("Testing %d octal       left_just .20 :%-.20o \n", d++, oc);
    // ft_printf("Testing %d octal       left_just  20 :%-20o \n", d++, oc);
    // ft_printf("Testing %d octal   left_just zero 20 :%-020o \n", d++, oc);
    // ft_printf("Testing %d octal               15.20 :%15.20o \n", d++, oc);
    // ft_printf("Testing %d octal               20.15 :%20.15o \n", d++, oc);
    // ft_printf("Testing %d octal    left_just  15.20 :%-15.20o \n", d++, oc);
    // ft_printf("Testing %d octal    left_just  20.15 :%-20.15o \n", d++, oc);
    // ft_printf("Testing %d octal a               .20 :%#.20o \n", d++, oc);
    // ft_printf("Testing %d octal a                20 :%#20o \n", d++, oc);
    // ft_printf("Testing %d octal a             20.10 :%#20.10o \n", d++, oc);
    // ft_printf("Testing %d octal a             10.20 :%#10.20o \n", d++, oc);
    // ft_printf("Testing %d octal a     left_just .20 :%#-.20o \n", d++, oc);
    // ft_printf("Testing %d octal a     left_just  20 :%#-20o \n", d++, oc);
    // ft_printf("Testing %d octal a left_just zero 20 :%#-020o \n", d++, oc);

    // ft_printf("\n\n\n");
    // ft_printf("\thex std::ft_printf\n\n");

    // ft_printf("Testing %d hex               .20 :%+.20x \n", d++, oc);
    // ft_printf("Testing %d hex                20 :%+20x \n", d++, oc);
    // ft_printf("Testing %d hex     left_just .20 :%+-.20x \n", d++, oc);
    // ft_printf("Testing %d hex     left_just  20 :%+-20x \n", d++, oc);
    // ft_printf("Testing %d hex left_just zero 20 :%+-020x \n", d++, oc);
    // ft_printf("Testing %d hex             15.20 :%+15.20x \n", d++, oc);
    // ft_printf("Testing %d hex             20.15 :%+20.15x \n", d++, oc);
    // ft_printf("Testing %d hex  left_just  15.20 :%+-15.20x \n", d++, oc);
    // ft_printf("Testing %d hex  left_just  20.15 :%+-20.15x \n", d++, oc);

    // ft_printf("\tHEX std::ft_printf\n\n");
    // ft_printf("Testing %d HEX               .20 :%+.20X \n", d++, oc);
    // ft_printf("Testing %d HEX                20 :%+20X \n", d++, oc);
    // ft_printf("Testing %d HEX     left_just .20 :%+-.20X \n", d++, oc);
    // ft_printf("Testing %d HEX     left_just  20 :%+-20X \n", d++, oc);
    // ft_printf("Testing %d HEX left_just zero 20 :%+-020X \n", d++, oc);
    // ft_printf("Testing %d HEX             15.20 :%+15.20X \n", d++, oc);
    // ft_printf("Testing %d HEX             20.15 :%+20.15X \n", d++, oc);
    // ft_printf("Testing %d HEX  left_just  15.20 :%+-15.20X \n", d++, oc);
    // ft_printf("Testing %d HEX  left_just  20.15 :%+-20.15X \n", d++, oc);
    // ft_printf("\n\n\n");
    // ft_printf("\tfloats std::ft_printf\n\n");

    // ft_printf("Testing %d floats                   :%f \n", d++, 0);
    // ft_printf("Testing %d floats left_just         :%-f \n", d++, 0);
    // ft_printf("Testing %d floats                   :%.0f \n", d++, 0);
    // ft_printf("Testing %d floats left_just         :%-.0f \n", d++, 0);
    // ft_printf("Testing %d floats                   :%#.0f \n", d++, 0);
    // ft_printf("Testing %d floats left_just         :%#-.0f \n", d++, 0);
    // ft_printf("Testing %d floats               .20 :%.20f \n", d++, fat);
    // ft_printf("Testing %d floats                20 :%20f \n", d++, fat);
    // ft_printf("Testing %d floats     left_just .20 :%-.20f \n", d++, fat);
    // ft_printf("Testing %d floats     left_just  20 :%-20f \n", d++, fat);
    // ft_printf("Testing %d floats left_just zero 20 :%-020f \n", d++, fat);
    // ft_printf("Testing %d floats           zero 20 :%020f \n", d++, fat);
    // ft_printf("Testing %d floats             15.20 :%15.20f \n", d++, fat);
    // ft_printf("Testing %d floats             20.15 :%20.15f \n", d++, fat);
    // ft_printf("Testing %d floats  left_just  15.20 :%-15.20f \n", d++, fat);
    // ft_printf("Testing %d floats  left_just  20.15 :%-20.15f \n", d++, fat);

    // ft_printf("\n\n\n");
    // ft_printf("\tlfloats std::ft_printf\n\n");

    // ft_printf("Testing %d floats                   :%lf \n", d++, f);
    // ft_printf("Testing %d floats left_just         :%-lf \n", d++, f);
    // ft_printf("Testing %d floats               .20 :%.20lf \n", d++, f);
    // ft_printf("Testing %d floats                20 :%20lf \n", d++, f);
    // ft_printf("Testing %d floats     left_just .20 :%-.20lf \n", d++, f);
    // ft_printf("Testing %d floats     left_just  20 :%-20lf \n", d++, f);
    // ft_printf("Testing %d floats left_just zero 20 :%-020lf \n", d++, f);
    // ft_printf("Testing %d floats           zero 20 :%020lf \n", d++, f);
    // ft_printf("Testing %d floats             15.20 :%15.20lf \n", d++, f);
    // ft_printf("Testing %d floats             20.15 :%20.15lf \n", d++, f);
    // ft_printf("Testing %d floats  left_just  15.20 :%-15.20lf \n", d++, f);
    // ft_printf("Testing %d floats  left_just  20.15 :%-20.15lf \n", d++, f);

    // ft_printf("\n\n\n");
    // ft_printf("\tLfloats std::ft_printf\n\n");
    // ft_printf("Testing %d floats                   :%Lf \n", d++, lf);
    // ft_printf("Testing %d floats left_just         :%-Lf \n", d++, lf);
    // ft_printf("Testing %d floats               .20 :%.20Lf \n", d++, lf);
    // ft_printf("Testing %d floats                20 :%20Lf \n", d++, lf);
    // ft_printf("Testing %d floats     left_just .20 :%-.20Lf \n", d++, lf);
    // ft_printf("Testing %d floats     left_just  20 :%-20Lf \n", d++, lf);
    // ft_printf("Testing %d floats left_just zero 20 :%-020Lf \n", d++, lf);
    // ft_printf("Testing %d floats           zero 20 :%020Lf \n", d++, lf);
    // ft_printf("Testing %d floats             15.20 :%15.20Lf \n", d++, lf);
    // ft_printf("Testing %d floats             20.15 :%20.15Lf \n", d++, lf);
    // ft_printf("Testing %d floats  left_just  15.20 :%-15.20Lf \n", d++, lf);
    // ft_printf("Testing %d floats  left_just  20.15 :%-20.15Lf \n", d++, lf);

    // ft_printf("\n\n\n");
    // ft_printf("\tsigned int std::ft_printf\n\n");

    // ft_printf("Testing %d signed int                   :%d \n", d++, i);
    // ft_printf("Testing %d signed int left_just         :%-d \n", d++, i);
    // ft_printf("Testing %d signed int               .20 :%.20d \n", d++, i);
    // ft_printf("Testing %d signed int                20 :%20d \n", d++, i);
    // ft_printf("Testing %d signed int     left_just .20 :%-.20d \n", d++, i);
    // ft_printf("Testing %d signed int     left_just  20 :%-20d \n", d++, i);
    // ft_printf("Testing %d signed int left_just zero 20 :%-020d \n", d++, i);
    // ft_printf("Testing %d signed int           zero 20 :%020d \n", d++, i);
    // ft_printf("Testing %d signed int             15.20 :%15.20d \n", d++, i);
    // ft_printf("Testing %d signed int             20.15 :%20.15d \n", d++, i);
    // ft_printf("Testing %d signed int  left_just  15.20 :%-15.20d \n", d++, i);
    // ft_printf("Testing %d signed int  left_just  20.15 :%-20.15d \n", d++, i);

    // ft_printf("\tsigned int std::ft_printf\n\n");
    // ft_printf("Testing %d signed int                   :%ld \n", d++, i);
    // ft_printf("Testing %d signed int left_just         :%-ld \n", d++, i);
    // ft_printf("Testing %d signed int               .20 :%.20ld \n", d++, i);
    // ft_printf("Testing %d signed int                20 :%20ld \n", d++, i);
    // ft_printf("Testing %d signed int     left_just .20 :%-.20ld \n", d++, i);
    // ft_printf("Testing %d signed int     left_just  20 :%-20ld \n", d++, i);
    // ft_printf("Testing %d signed int left_just zero 20 :%-020ld \n", d++, i);
    // ft_printf("Testing %d signed int           zero 20 :%020ld \n", d++, i);
    // ft_printf("Testing %d signed int             15.20 :%15.20ld \n", d++, i);
    // ft_printf("Testing %d signed int             20.15 :%20.15ld \n", d++, i);
    // ft_printf("Testing %d signed int  left_just  15.20 :%-15.20ld \n", d++, i);
    // ft_printf("Testing %d signed int  left_just  20.15 :%-20.15ld \n", d++, i);

    // ft_printf("\tsigned int std::ft_printf\n\n");
    // ft_printf("Testing %d signed int                   :% lld \n", d++, i);
    // ft_printf("Testing %d signed int left_just         :% -lld \n", d++, i);
    // ft_printf("Testing %d signed int               .20 :% .20lld \n", d++, i);
    // ft_printf("Testing %d signed int                20 :% 20lld \n", d++, i);
    // ft_printf("Testing %d signed int     left_just .20 :% -.20lld \n", d++, i);
    // ft_printf("Testing %d signed int     left_just  20 :% -20lld \n", d++, i);
    // ft_printf("Testing %d signed int left_just zero 20 :% -020lld \n", d++, i);
    // ft_printf("Testing %d signed int           zero 20 :% 020lld \n", d++, i);
    // ft_printf("Testing %d signed int             15.20 :% 15.20lld \n", d++, i);
    // ft_printf("Testing %d signed int             20.15 :% 20.15lld \n", d++, i);
    // ft_printf("Testing %d signed int  left_just  15.20 :% -15.20lld \n", d++, i);
    // ft_printf("Testing %d signed int  left_just  20.15 :% -20.15lld \n", d++, i);

    // ft_printf("\tsigned int std::ft_printf\n\n");
    // ft_printf("Testing %d signed int                   :%lld \n", d++, i);
    // ft_printf("Testing %d signed int left_just         :%-lld \n", d++, i);
    // ft_printf("Testing %d signed int               .20 :%.20lld \n", d++, i);
    // ft_printf("Testing %d signed int                20 :%20lld \n", d++, i);
    // ft_printf("Testing %d signed int     left_just .20 :%-.20lld \n", d++, i);
    // ft_printf("Testing %d signed int     left_just  20 :%-20lld \n", d++, i);
    // ft_printf("Testing %d signed int left_just zero 20 :%-020lld \n", d++, i);
    // ft_printf("Testing %d signed int           zero 20 :%020lld \n", d++, i);
    // ft_printf("Testing %d signed int             15.20 :%15.20lld \n", d++, i);
    // ft_printf("Testing %d signed int             20.15 :%20.15lld \n", d++, i);
    // ft_printf("Testing %d signed int  left_just  15.20 :%-15.20lld \n", d++, i);
    // ft_printf("Testing %d signed int  left_just  20.15 :%-20.15lld \n", d++, i);

    // ft_printf("\tsigned int std::ft_printf\n\n");
    // ft_printf("\tsigned int std::ft_printf\n\n");
    // ft_printf("Testing %d signed int                   :%#+hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int left_just         :%#+-hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int               .20 :%#+.20hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int                20 :%#+20hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int     left_just .20 :%#+-.20hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int     left_just  20 :%#+-20hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int left_just zero 20 :%#+-020hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int           zero 20 :%#+020hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int             15.20 :%#+15.20hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int             20.15 :%#+20.15hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int  left_just  15.20 :%#+-15.20hhlllo \n", d++, oc);
    // ft_printf("Testing %d signed int  left_just  20.15 :%#+-20.15hhlllo \n", d++, oc);

    // ft_printf("\tpointers std::ft_printf\n\n");

    // ft_printf("Testing %d pointer                  :%+p \n", d++, p);
    // ft_printf("Testing %d pointerleft_just         :%+-p \n", d++, p);
    // ft_printf("Testing %d pointer              .20 :%+.20p \n", d++, p);
    // ft_printf("Testing %d pointer               20 :%+20p \n", d++, p);
    // ft_printf("Testing %d pointer    left_just .20 :%+-.20p \n", d++, p);
    // ft_printf("Testing %d pointer    left_just  20 :%+-20p \n", d++, p);
    // ft_printf("Testing %d pointerleft_just zero 20 :%+-020p \n", d++, p);
    // ft_printf("Testing %d pointer          zero 20 :%+020p \n", d++, p);
    // ft_printf("Testing %d pointer            15.20 :%+15.20p \n", d++, p);
    // ft_printf("Testing %d pointer            20.15 :%+20.15p \n", d++, p);
    // ft_printf("Testing %d pointer left_just  15.20 :%+-15.20p \n", d++, p);
    // ft_printf("Testing %d pointer left_just  20.15 :%+-20.15p \n", d++, p);

    // ft_printf("\thex std::ft_printf\n\n");

    // ft_printf("Testing %d hex               .20 :%.20x \n", d++, oc);
    // ft_printf("Testing %d hex                20 :%20x \n", d++, oc);
    // ft_printf("Testing %d hex     left_just .20 :%-.20x \n", d++, oc);
    // ft_printf("Testing %d hex     left_just  20 :%-20x \n", d++, oc);
    // ft_printf("Testing %d hex left_just zero 20 :%-020x \n", d++, oc);
    // ft_printf("Testing %d hex             15.20 :%15.20x \n", d++, oc);
    // ft_printf("Testing %d hex             20.15 :%20.15x \n", d++, oc);
    // ft_printf("Testing %d hex  left_just  15.20 :%-15.20x \n", d++, oc);
    // ft_printf("Testing %d hex  left_just  20.15 :%-20.15x \n", d++, oc);

    // ft_printf("\tHEX std::ft_printf\n\n");
    // ft_printf("Testing %d HEX               .20 :% .20X \n", d++, oc);
    // ft_printf("Testing %d HEX                20 :% 20X \n", d++, oc);
    // ft_printf("Testing %d HEX     left_just .20 :% -.20X \n", d++, oc);
    // ft_printf("Testing %d HEX     left_just  20 :% -20X \n", d++, oc);
    // ft_printf("Testing %d HEX left_just zero 20 :% -020X \n", d++, oc);
    // ft_printf("Testing %d HEX             15.20 :% 15.20X \n", d++, oc);
    // ft_printf("Testing %d HEX             20.15 :% 20.15X \n", d++, oc);
    // ft_printf("Testing %d HEX  left_just  15.20 :% -15.20X \n", d++, oc);
    // ft_printf("Testing %d HEX  left_just  20.15 :% -20.15X \n", d++, oc);

    // ft_printf("\n\tcharss std::ft_printf\n\n");

    // ft_printf("Testing %d char               .20 :% .20c\n", d++, i);
    // ft_printf("Testing %d char                20 :% 20c\n", d++, i);
    // ft_printf("Testing %d char     left_just .20 :% -.20c\n", d++, i);
    // ft_printf("Testing %d char     left_just  20 :% -20c\n", d++, i);
    // ft_printf("Testing %d char left_just zero 20 :% -020c\n", d++, i);
    // ft_printf("Testing %d char             15.20 :% 15.20c\n", d++, i);
    // ft_printf("Testing %d char             20.15 :% 20.15c\n", d++, i);
    // ft_printf("Testing %d char  left_just  15.20 :% -15.20c\n", d++, i);
    // ft_printf("Testing %d char  left_just  20.15 :% -20.15c\n", d++, i);

    // ft_printf("Testing %d char               .20 :%0.20c\n", d++, i);
    // ft_printf("Testing %d char                20 :%020c\n", d++, i);
    // ft_printf("Testing %d char     left_just .20 :%0-.20c\n", d++, i);
    // ft_printf("Testing %d char     left_just  20 :%0-20c\n", d++, i);
    // ft_printf("Testing %d char left_just zero 20 :%0-020c\n", d++, i);
    // ft_printf("Testing %d char             15.20 :%015.20c\n", d++, i);
    // ft_printf("Testing %d char             20.15 :%020.15c\n", d++, i);
    // ft_printf("Testing %d char  left_just  15.20 :%0-15.20c\n", d++, i);
    // ft_printf("Testing %d char  left_just  20.15 :%0-20.15c\n", d++, i);

    // ft_printf("Testing %d char               .20 :%0 .20c\n", d++, i);
    // ft_printf("Testing %d char                20 :%0 20c\n", d++, i);
    // ft_printf("Testing %d char     left_just .20 :%0 -.20c\n", d++, i);
    // ft_printf("Testing %d char     left_just  20 :%0 -20c\n", d++, i);
    // ft_printf("Testing %d char left_just zero 20 :%0 -020c\n", d++, i);
    // ft_printf("Testing %d char             15.20 :%0 15.20c\n", d++, i);
    // ft_printf("Testing %d char             20.15 :%0 20.15c\n", d++, i);
    // ft_printf("Testing %d char  left_just  15.20 :%0 -15.20c\n", d++, i);
    // ft_printf("Testing %d char  left_just  20.15 :%0 -20.15c\n", d++, i);
    ft_printf("@moulitest: %#.x %#.0x", 0, 0);
    ft_printf("how? :%-%:%-10%:%-010%:%-.10%:%-0.10%:\n");
    ft_printf("how? :%%:%10%:%010%:%.10%:%0.10%:\n");
    ft_printf("how? :%-#l%:%-#10h%:%-#010hh%:%#-.10L%:%-0#0.10ll%:\n");
    printf("%s%s%s\n", "\0\0\0\0\0\0", "aaaaaa", NULL);
    ft_printf("%s%s%s", "this", "is my string", "dude bro\n");
    printf("Testing %d %20.10c\n",d++, '\0');
    ft_printf("Testing %d %20.10c\n",d++, 0);
    printf("Testing %d %.3s\n",d++, 0);
    ft_printf("Testing %d %.3s\n",d++, 0);
    printf("Testing %d %.1s\n",d++, NULL);
    ft_printf("Testing %d %.1s\n",d++, NULL);
    printf("Testing %d %.c\n",d++, 0);
    ft_printf("Testing %d %.c\n",d++, 0);
    printf("Testing %d %c \n",d++, NULL);
    ft_printf("Testing %d %c\n",d++, NULL);
    printf("Testing %d %0#lx\n", d++, oc);
    printf("Testing %d %0#lx\n", d++, oc);
    printf("Testing %d %0#lx\n", d++, oc);
    printf("Testing %i %0#lx\n", d++, oc);
    printf("Testing %d %0#lx\n", d++, oc);
    printf("Testing %d %lx\n", d++, oc);
    printf("Testing %d %lx\n", d++, oc);
    printf("Testing %d %lx\n", d++, oc);
    printf("Testing %i %lx\n", d++, oc);
    printf("Testing %d %lx\n", d++, oc);

    ft_printf("Testing %d %#lx\n", d++, oc);
    ft_printf("Testing %d %#lx\n", d++, oc);
    ft_printf("Testing %d %#lx\n", d++, oc);
    ft_printf("Testing %i %#lx\n", d++, oc);
    ft_printf("Testing %d %#lx\n", d++, oc);
    ft_printf("Testing %d %lx\n", d++, oc);
    ft_printf("Testing %d %lx\n", d++, oc);
    ft_printf("Testing %d %lx\n", d++, oc);
    ft_printf("Testing %i %lx\n", d++, oc);
    ft_printf("Testing %d %lx\n", d++, oc);
    ft_printf("%d\n", -1);
    ft_printf("%#6o", 2500);
    
    getchar();
}