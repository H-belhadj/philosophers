#include "philosophers.h"

void ft_putchar(char c)
{
    write(2, &c, 1);
}

void ft_putstr(char *str)
{
    int i;

    i = -1;
    while(str[++i])
        ft_putchar(str[i]);
}
int write_error(char *str)
{
    ft_putstr("ERROR: ");
    ft_putstr(str);
    return 1;
}