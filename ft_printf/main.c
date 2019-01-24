#include <stdio.h>

int main(void)
{
    short i;

    i = 1234567890;
    printf("Testing string left_just .20 %-.20hd \n", 1234567890);
    printf("Testing string           .20 %.20hd \n", 1234567890);
    printf("Testing string left_just -20 %-20hd \n", 1234567890);
    printf("Testing string         08.20 %8.20hd \n", 1234567890);
}