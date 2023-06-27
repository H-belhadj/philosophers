#include "philo.h"

t_list *arg_value(t_list *list, int argc, char **argv)
{
    list->number_of_philosophers = ft_atoi(argv[1]);
    list->time_to_die = ft_atoi(argv[2]);
    list->time_to_eat = ft_atoi(argv[3]);
    list->time_to_sleep = ft_atoi(argv[4]);
    list->number_of_times_each_philosopher_must_eat = -1;

    if(argc == 6)
        list->number_of_times_each_philosopher_must_eat = ft_atoi(argv[5]);
    return (list);
}
