
#include "libftprintf.h"

int main(void) {
    char    *s = NULL;
    int     i;

    printf("pp%-4.1p\n", s);
    i = 1;
    ft_printf("aa%-4.1p\n", s);
}