#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include <stdio.h>     // For standard input/output functions
#include <stdlib.h>    // For general-purpose functions such as memory allocation
#include <pthread.h>   // For thread creation and synchronization
#include <unistd.h>    // For sleep() function (optional)

typedef struct s_list{
    int number_of_philosophers;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_times_each_philosopher_must_eat;
}t_list;

void arg_value(t_list *list, char **argv);
int ft_atoi(char *str);
int	ft_isdigists(int c);
int	ft_validint(char *str);

#endif