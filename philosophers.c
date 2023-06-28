#include "philo.h"

int main(int argc, char **argv)
{
    t_list  *list;
    t_philo *philo;
    
    (void)philo;
    list = malloc(sizeof(t_list));
    if (cheack(argc, argv))
        return 1;
    list = arg_value(list, argc, argv);
    philo = ft_philo(list);
    return 0;
}
